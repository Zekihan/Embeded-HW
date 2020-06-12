#!/bin/bash

DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"
cd $DIR

gcc ../source/horner_poly_unop.c -o ../out/horner_poly_unop_out
gcc ../source/poly_unop.c -o ../out/poly_unop_out

sum=0
for i in {1..10}
do
    OUTPUT=$(../out/horner_poly_unop_out)
    sum=$(echo "scale=9; ${sum} + ${OUTPUT}" | bc)
done
echo Horner Poly Unoptimized
echo "scale=9; ${sum} / 10" | bc

sum=0
for i in {1..10}
do
    OUTPUT=$(../out/poly_unop_out)
    sum=$(echo "scale=9; ${sum} + ${OUTPUT}" | bc)
done
echo Poly Unoptimized
echo "scale=9; ${sum} / 10" | bc