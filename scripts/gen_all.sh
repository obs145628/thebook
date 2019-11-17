#!/bin/bash

while IFS= read -r line
do
    URL=$(echo $line | cut -d "|" -f 1)
    BRANCH=$(echo $line | cut -d "|" -f 2)
    DIR=$(echo $line | cut -d "|" -f 3)
    ./scripts/gen_from_git.sh $URL $BRANCH $DIR
done < $1
