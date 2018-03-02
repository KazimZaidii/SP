#!/bin/bash

UNIX=( Debian 'Red hat' Ubuntu Suse Fedora )
echo  "Array:	"${UNIX[*]}
echo "Length:	"${#UNIX[*]}
echo "Length:	"${#UNIX[2]}
echo "Two elements from position 3 are: "
echo ${UNIX[3]}
echo ${UNIX[4]}

#temp=(${Unix[@]}) "AIX" "LOL")

UNIX[5]=AIX
UNIX[6]=HP-UX
echo "replacing array index: "${UNIX[*]/"Ubuntu"/"SCO Unix"}
echo "new array:	"${UNIX[*]}
unset UNIX[2]
echo "array after removing second index:	"${UNIX[*]}

LINUX=( ${UNIX[*]} )
echo "New LINUX array:	" ${LINUX[*]}

BASH=( ${LINUX[*]} "" ${UNIX[*]} )

echo "Bash array:	"${BASH[*]}
unset LINUX[*]
unset UNIX[*]

echo "LINUX Empty: " ${LINUX[*]}
echo "UNIX Empty: " ${LINUX[*]}

