#!/bin/bash

if [ $# -lt 2 ]
then
    echo "Not enough arguments specified"
    exit 1
fi

if [ -f "$1" ]
then
    echo "$2" > "$1"
else
    install -m 644 -D /dev/null "$1"
    echo "$2" >> "$1"
fi

if [ $? -ne 0 ]
then
    echo "Failed to write to file"
fi