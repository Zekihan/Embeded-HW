#!/bin/bash

DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"
cd $DIR

bash test.sh > ../out.txt

python3 toExcel.py -i ../out.txt -o ../out.xlsx