#!/bin/sh
cd ../q1
make
cat ../tests/expr1.txt | ./ExprTree > out1.txt

d1=$(diff ../tests/outputs/q1o1.txt out1.txt -qZB)
if [ -z "$d1" ]
then 
    echo "Test1 passed"
else
    echo "Test1 failed"
fi

cat ../tests/expr2.txt | ./ExprTree > out1.txt
d1=$(diff ../tests/outputs/q1o2.txt out1.txt -qZB)
if [ -z "$d1" ]
then 
    echo "Test2 passed"
else
    echo "Test2 failed"
fi

cat ../tests/expr3.txt | ./ExprTree > out1.txt
d1=$(diff ../tests/outputs/q1o3.txt out1.txt -qZB)
if [ -z "$d1" ]
then 
    echo "Test3 passed"
else
    echo "Test3 failed"
fi

rm out1.txt