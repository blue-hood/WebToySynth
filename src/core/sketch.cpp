#include "sketch.hpp"

#define PTHREAD_POOL_SIZE 8

#include <exception>
#include <stdexcept>
#include <pthread.h>
#include <algorithm>
#include <deque>

// uuid を返す
void Sketch::appendCom(Component *com)
{
	this->coms.push_back(Component_up(com));
}

// uuid で参照
void Sketch::removeCom(Component_up &rm)
{
	this->coms.erase(remove_if(this->coms.begin(), this->coms.end(), [&](Component_up &com) -> bool { return com == rm; }), this->coms.end());
}

void Sketch::upInterface()
{
	this->int_ins.clear();
	this->int_outs.clear();
	for (Component_up &com : this->coms)
	{
		vector<PortIn_p> int_ins = com->getIntIns();
		this->int_ins.insert(this->int_ins.end(), int_ins.begin(), int_ins.end());

		vector<PortOut_p> int_outs = com->getIntOuts();
		this->int_outs.insert(this->int_outs.end(), int_outs.begin(), int_outs.end());
	}
}

void Sketch::onSimStart()
{
	for (Component_up &com : this->coms)
	{
		com->onSimStart();
	}
}

void *test(void *args)
{
	printf("thread\n");
	//deque<Component *> *chcoms = new deque<Component *>(); // メモリリークに注意
	//static_cast<Component *>(com)->onChangeIn(*chcoms);
	//return chcoms;
	return args;
}

void Sketch::onChangeTime(double dt)
{
	vector<pthread_t> threads;

	try
	{
		deque<Component *> chcoms;

		for (Component_up &com : this->coms)
		{
			com->onChangeTime(dt, chcoms);
		}

		int threadCount = 0;
		while (!chcoms.empty())
		{
			for (int i = 1; i < PTHREAD_POOL_SIZE && !chcoms.empty(); i++)
			{
				Component *com = chcoms.front();
				chcoms.pop_front();

				pthread_t thread;

				printf("create %d\n", ++threadCount);
				if (pthread_create(
						&thread, NULL,
						test,
						/*com*/ NULL))
				{
					throw runtime_error("スレッドを作成できません。");
				};
				threads.push_back(thread);
			}

			for (pthread_t thread : threads)
			{
				deque<Component *> *part_chcoms;

				printf("join %d\n", --threadCount);
				if (pthread_join(thread, reinterpret_cast<void **>(&part_chcoms)))
				{
					throw runtime_error("スレッドの待機に失敗しました。");
				}
				//for (Component *com : *part_chcoms)
				//{
				//	chcoms.push_back(com);
				//}
				//delete part_chcoms;
			}
			threads.clear();
		}
	}
	catch (exception &e)
	{
		for (pthread_t &thread : threads)
		{
			deque<Component *> *part_chcoms;

			if (!pthread_join(thread, (void **)&part_chcoms))
			{
				delete part_chcoms;
			}
		}
		throw e;
	}
}

void Sketch::onSimEnd()
{
	for (Component_up &com : this->coms)
	{
		com->onSimEnd();
	}
}

void Sketch::exportExtends()
{
	for (Component_up &com : this->coms)
	{
		com->exportExtends();
	}
}

/*
	export(){
		var ex = {};
		ex.coms = [];
		this.coms.forEach((com) => {
			ex.coms.push(com.export());
		});
		return ex;
	}

	import(im){
		this.clearCom();
		var lut = [];
		im.coms.forEach((im) => {
			var com = eval("new "+im.type+"()");
			lut = lut.concat(com.import(im));
			this.appendCom(com);
		});

		var comlut = [];
		this.coms.forEach((com) => {
			com.connectById(lut);
			comlut.push({ id: com.id, inst: com });
		});
		return comlut;
	}
};
*/