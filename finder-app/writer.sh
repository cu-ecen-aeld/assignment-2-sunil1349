#!/bin/bash

arguments=$#

if [ ${arguments} != 2 ] 
then
    echo "error does not have correct number of arguments"
    exit 1
else
    writefile=$1
    writestr=$2
fi

dir=$(dirname ${writefile})

mkdir -p ${dir}
if [ $? -ne 0 ]
then
    echo "Error  : failed to create dir"
    exit 1
fi

echo "${writestr}" > ${writefile}
if [ $? -ne 0 ]
then
    echo "Error : not able to create file ${writefile}"
    exit 1
fi 