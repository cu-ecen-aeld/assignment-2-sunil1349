#!/bin/bash

arguments=$#

if [ ${arguments} != 2 ] 
then
    echo "error does not have correct number of arguments"
    exit 1
else
    filesdir=$1
    searchstr=$2
fi

if [ ! -d ${filesdir} ];
then
    echo "Error: Directory ${filesdir} does not exist or is not a directory."
    exit 1
fi


x=$(find ${filesdir} -type f| wc -l )

y=$(grep -R ${searchstr} ${filesdir} 2>/dev/null| wc -l)


echo "The number of files are ${x} and the number of matching lines are ${y}" 