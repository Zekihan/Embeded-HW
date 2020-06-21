#!/bin/bash

DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"
cd $DIR

gcc ../source/horner_poly_unop.c -o ../out/horner_poly_unop_out
gcc ../source/horner_poly_op1.c -o ../out/horner_poly_op1_out
gcc ../source/poly_unop.c -o ../out/poly_unop_out

echo Horner Poly unoptimized
for i in {1..10}
do
    ../out/horner_poly_unop_out
done

echo Horner Poly optimized 1
for i in {1..10}
do
../out/horner_poly_op1_out
done

echo Poly Unoptimized
for i in {1..10}
do
    ../out/poly_unop_out
done