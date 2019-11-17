#!/bin/bash

URL=$1
BRANCH=$2
DIR=$3


mkdir -p ./tmp
git clone -b $BRANCH $URL ./tmp/data

NEW_DIR=$(sed -r 's/[^ ]*\/\/[^/]*\/([^/]*)\/([^/]*)\.git/\1_\2/' <<<$URL)
rm -rf ./extern/$NEW_DIR
mv ./tmp/data/$DIR ./extern/$NEW_DIR
python3 ./scripts/gen_code.py ./extern/$NEW_DIR
rm -rf ./tmp
