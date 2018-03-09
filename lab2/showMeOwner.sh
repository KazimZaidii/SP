#!/bin/bash

showAllOwners()
{

	username=$1
	for i in `ls`
	do
		set `ls -li $i`
		shift
		if [ -f $i ]
		then

			if [ $username = $3 ]
			then
				echo "FileOwner:" $3
			
				echo "FileName: "$9
			fi
		fi
	done
}



if [ $# -eq 0 ]
	then
	echo "No arguments provided"
fi

if [ $# -gt 1 ]
	then
	echo "Invalid number of arguments"
fi

cd ~/
showAllOwners $1
