#!/bin/bash

gcc -O3 horner_poly_unop.c -o horner_poly_unop_out
gcc -O3 poly_unop.c -o poly_unop_out

sum=0.000000000
for i in {1..10}
do
    OUTPUT=$(./horner_poly_unop_out)
    sum=$(echo "scale=9; ${sum} + ${OUTPUT}" | bc)
done
echo Horner Poly Unoptimized
echo "scale=9; ${sum} / 10.000000" | bc

sum=0.000000000
for i in {1..10}
do
    OUTPUT=$(./poly_unop_out)
    sum=$(echo "scale=9; ${sum} + ${OUTPUT}" | bc)
done
echo Poly Unoptimized
echo "scale=9; ${sum} / 10.000000" | bc