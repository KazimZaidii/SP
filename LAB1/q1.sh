#!/bin/bash

read -p "enter first number: " num1
read -p "enter second number:" num2
check=1
expr $num1 + 0
if [ $? -eq 0 ]
then
echo " first number is valid "
else
echo " first number is not valid "
check=0
fi

expr $num2 + 0
if [ $? -eq 0 ]
then
echo " second number is valid "
else
echo " second number is not valid "
check=0
fi

if [ $check -eq 1 ]
then
echo "result: "` expr $num1 + $num2 `
echo "result: "` expr $num1 - $num2 `
echo "result: "` expr $num1 \* $num2 `
echo "result: "` expr $num1 % $num2 `
echo "result: "` expr $num1 / $num2 `
fi



