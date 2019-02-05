#!/bin/sh

. ./config

docker build ./ -t troopa
docker run -d --name troopa -v `pwd`/html:/var/www/html -p ${PORT}:80 troopa
