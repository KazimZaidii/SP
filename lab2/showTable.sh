#!/bin/bash

showTable()
{
	if [ $# -eq 1 ]
		then
		echo "proceeding with one argument"
		value=$1
		for i in `seq 1 10`
		do
			echo "$value * $i " `expr $value \* $i`
		done
	fi 
	
	#for -s

	if [ $# -eq 3 ]
		then
		operation=$2
		if [ $operation = "-s" ]
		then
			base=$1
			start=$3
			for i in `seq $start 10`
			do
				echo "$base * $i " `expr $base \* $i`
			done
	
		elif [ $operation = "-e" ]
		then
			base=$1
			end=$3
			for i in `seq 1 $end`
			do
				echo "$base * $i" `expr $base \* $i`
			done
		fi 
	fi

	if [ $# -eq 5 ]
		then
		base=$1
		operation1=$2
		start=$3
		operation2=$4
		end=$5
		if [ $operation1 = "-s" ] && [ $operation2 = "-e" ]
		then
			for i in `seq $start $end`
			do
				echo "$base * $i" `expr $base \* $i`
			done
		fi
	fi

	if [ $# -eq 6 ]
		then
		base=$1
		operation1=$2
		start=$3
		operation2=$4
		reverse=$6
		j=$5
		while [ $j -gt $start ]
		do
			echo "$base * $j" `expr $base \* $j`
			j=`expr $j - 1`
		done
	fi
		
}


if [ $# -eq 0 ]
	then
	echo "No arguments provided"
fi

if [ $# -gt 6 ]
	then
	echo "Invalid No of Arguments"
fi
if [ $# -eq 2 ]
	then
	echo "Invalid No of Arguments"
fi
if [ $# -eq 4 ]
	then
	echo "Invalid No of Arguments"
fi

showTable $@



