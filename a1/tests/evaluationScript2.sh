#!/bin/sh
cd ../q2
make
./TreeSearch ../tests/num1.txt ../tests/query1.txt > out1.txt
o=$(head -1 out1.txt | grep "A2a:5,")
if [ -z $o ]
then
    echo "Test1 failed"
else
    echo "Test1 passed"
fi

./TreeSearch ../tests/num2.txt ../tests/query2.txt > out1.txt
o=$(head -1 out1.txt | grep "A2a:68," )
if [ -z $o ]
then
    echo "Test2 failed"
else
    echo "Test2 passed"
fi

./TreeSearch ../tests/num3.txt ../tests/query3.txt > out1.txt
o=$(head -1 out1.txt | grep "^A2a:277,")
if [ -z $o ]
then
    echo "Test3 failed"
else
    echo "Test3 passed"
fi

rm out1.txt