#!/bin/bash

RemoveDuplicateLines()
{
	file=$1
	echo $file
	if [ -f $file ]
	then
		echo "file before: "
		cat $file
		echo "processing"
	else
		echo "file not found"
		exit
	fi
	echo "file after processing: "
	sort $file | uniq
	
}

fileName=$1
RemoveDuplicateLines $1
