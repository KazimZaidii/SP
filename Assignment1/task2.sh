#!/bin/bash


generatefiles()
{
	file=$1
	awk 'NR%2==0' $file > evenfile
	awk 'NR%2!=0' $file > oddfile 
}


fileName=$1
if [ -f $fileName ]
	then
		echo "processing"
		generatefiles $fileName
	else
		echo "file not found"
fi

