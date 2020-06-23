#!/bin/bash

DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"
cd $DIR

gcc ../source/pp.c -o ../out/pp_o1 -O1
gcc ../source/pp.c -o ../out/pp_o2 -O2
gcc ../source/pp.c -o ../out/pp_o3 -O3
gcc ../source/pp.c -o ../out/pp_ofast -Ofast

echo O1
for i in {1..10}
do
    echo $i
    ../out/pp_o1
done

echo O2
for i in {1..10}
do
    echo $i
    ../out/pp_o2
done

echo O3
for i in {1..10}
do
    echo $i
    ../out/pp_o3
done

echo Ofast
for i in {1..10}
do
    echo $i
    ../out/pp_ofast
done