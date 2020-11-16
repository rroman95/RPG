#!/bin/bash

IFS=$'\n'


./project units/adventurer.json units/monster.json >> output.txt
./project units/adventurer.json units/zombie.json >> output.txt
./project units/adventurer.json units/szomszedneni.json >> output.txt

