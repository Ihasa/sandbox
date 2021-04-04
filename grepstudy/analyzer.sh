#!/bin/bash
STATE=1
while read line
do
    lineX=$line
    [[ $lineX =~ ^(.*)[[:blank:]] ]];
    echo "$line -> ${BASH_REMATCH[0]}"
done < $1

if [ $STATE -eq 1 ] || [ $STATE -eq 4 ]; then
    echo "OK:$STATE"
else
    echo "NG:$STATE"
fi
