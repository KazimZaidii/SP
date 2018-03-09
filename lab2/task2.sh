#!/bin/bash

RunningProcess()
{
	
	ps -all -A | grep $1
	
	if [ $? -eq 0 ]
	then
		status='running'
	else
		status='not running'
	fi	
	set `ps -all -A | grep $1`
	
	pid=$4
	ppid=$5
	shift 5
	echo "PID: "$pid
	echo "NAME: "$9
	echo "PPID: "$ppid
	echo "STATUS: "$status
}

RunningProcess $1
