#!/bin/bash

IFS=$'\n'


./project units/thor.json units/loki.json >> output.txt
./project units/thor.json units/hulk.json >> output.txt
./project units/loki.json units/thor.json >> output.txt
./project units/loki.json units/hulk.json >> output.txt 
./project units/hulk.json units/thor.json >> output.txt
./project units/hulk.json units/loki.json >> output.txt
