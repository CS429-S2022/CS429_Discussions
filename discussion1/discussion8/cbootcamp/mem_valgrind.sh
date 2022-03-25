#!/bin/bash
FILE=mem_mgmt

gcc --std=c99 -o $FILE $FILE.c

if [ -f $FILE ];
then
    echo "$FILE exists."
    echo "Running valgrind on ./$FILE..."
    valgrind --tool=memcheck --leak-check=full ./$FILE
else
   echo "File ./$FILE does not exist. Compile first"
fi

