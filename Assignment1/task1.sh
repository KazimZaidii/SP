#!/bin/bash

OrganizeFiles()
{
	for file in *.???
	do
		[ -f $file ] || continue
		dirName=`echo $file | rev | cut -c-3 | rev`
		mkdir $dirName 2>err
		mv $file $dirName
	done
}

OrganizeFiles
