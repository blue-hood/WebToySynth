#!/bin/sh
docker build ./ -t troopa
docker run -d --name troopa -v `pwd`/html:/var/www/html troopa
