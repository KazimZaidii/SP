#!/bin/bash

Is_lower()
{
	string=$1
	result=`echo $string | awk '{print tolower($0)}'`
	echo $result	
}

Is_root()
{
	if [ "$EUID" -ne 0 ]
	then
		return 1
	else
		return 0
	fi
}
Is_user_exists()
{
	read -p "enter username to check: " name
	id -u $name
	if [ $? -eq 0 ]
	then
		echo "user exists"
	else
		echo "user doesn't exist"
	fi
}	

string=$1
Is_lower $string
if Is_root  
then
	echo "Script executed by root"
else
	echo "This Script is not executed by root"
fi
Is_user_exists
