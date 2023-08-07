#!/bin/bash

task_name="$1"

echo "Creating dir $1"
mkdir "$1"
mkdir "$1/build"
echo "Done"

echo "Copying run script"
cp "conf/run.sh" "$1/"
chmod 700 "$1/run.sh"
echo "Done"

echo "Creating CMakeLists.txt"
cp "conf/CMakeLists.txt" "$1"
sed -i "" "s/{EXECUTABLE}/$1/" "$1/CMakeLists.txt"
sed -i "" "s/{SOURCE}/$1.cpp/" "$1/CMakeLists.txt"
echo "Done"

echo "Creating executable $1.cpp"
touch "$1/$1.cpp"
echo "Done"