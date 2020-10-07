COUNTER_FILE="ex2.txt"
tfile=$(mktemp ./lock.XXXX)
lockfile=./lockfile
#some parts of code was seen here: https://unix.stackexchange.com/questions/309010/how-to-do-locking-a-file-from-a-shell-script

if ln $tpfile $lockfile ; then 
for i in {1..100}
do
    count=$( tail -n 1 ex2.txt )
	((count++))
	echo $count >> $COUNTER_FILE
done
    rm $lockfile

else 
    echo 1
fi
rm $tfile
