#!/bin/bash

userone=$2
file1=$1
usertwo=$4
file2=($3)
set `ls -li $1` 
owner=$5
echo "OWNER: " $5
echo "GROUP: " $4
echo "PERMISSIONS: " $2
shift
echo "FILENAME: " $9
if [ $owner = $userone ] 
	then
	echo "CHEATING: " 0
else
	echo "CHEATING: " 1
fi

if ( test ${#file2[*]} -gt 0 )
then
	set `ls -li ${file2[0]}` 
	echo "OWNER: " $5
	echo "GROUP: " $4
	echo "PERMISSIONS: " $2
	shift
	echo "FILENAME: " $9
	diff -c $file1 $9
	if [ $? -eq 0 ]
	then 
	echo "NO CHEATING"
	else
	echo "CHEATING"
	fi
fi
