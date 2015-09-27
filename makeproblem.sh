#!/usr/bin/env bash

mkdir ~/Documents/__CS__/Euler/P${1}
touch ~/Documents/__CS__/Euler/P${1}/euler${1}.c
touch ~/Documents/__CS__/Euler/P${1}/makefile
echo -e "euler${1}.a:euler${1}.c\n\tgcc euler${1}.c -o euler${1}.a" > ~/Documents/__CS__/Euler/P${1}/makefile
