#!/bin/bash
filename = "text.txt"


if ln -snf  $filename lfile.lock; then

for i in {1..100}
do
num =  ${tail -n 1 $filename}
((num++))
echo $num >> $filename

done
rm lfile.lock
else
echo no files has been locked
fi

