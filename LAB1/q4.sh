#!/bin/bash

arr=( `cat "file.txt"` )
echo "Array:	"${arr[*]}
echo "Array Length:	"${#arr[*]}
echo "Length of 3rd index:	"${#arr[2]}

