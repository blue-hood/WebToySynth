#!/bin/sh

. ./config

docker build ./ -t webtoysynth
docker run -d --name webtoysynth -v `pwd`/html:/var/www/html -p ${PORT}:80 webtoysynth
