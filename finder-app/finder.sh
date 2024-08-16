#!/bin/bash

if [ $# -lt 2 ]
then
	echo "Not enough parameters specified"
	exit 1
elif [ -d "$1" ]
then
	fileCount=$(find $1 -type f | wc -l)
	matchCount=$(grep -r $2 $1 | wc -l)
	echo "The number of files are ${fileCount} and the number of matching lines are ${matchCount}"
    exit 0
else
	echo "Directory: $1 does not exist"
	exit 1
fi
