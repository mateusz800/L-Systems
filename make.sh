#!/bin/bash
OBJECTS=""
EXECUTABLE=`ls ./src/*.cpp`
EXECUTABLE="`echo $EXECUTABLE` `ls ./src/Components/*.cpp`"
for file in $EXECUTABLE
do
  NAME=`echo ${file[@]} |cut -d "/" -f 3,4 | cut -d "." -f 1`
  REPEATED=`echo $OBJECTS | grep build/$NAME.o`
  if [[ "$REPEATED" != *"build/$NAME.o"* ]]
  then
    OBJECTS="$OBJECTS build/$NAME.o"
    g++ -c "src/$NAME.cpp" -o "build/$NAME.o"
  fi


done
OBJECTS=`echo $OBJECTS | sort -u`
g++ $OBJECTS -o ./lsystem -lsfml-graphics -lsfml-window -lsfml-system
