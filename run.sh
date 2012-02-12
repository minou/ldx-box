#!/bin/bash
lib=libdx.so

if [ $# == 0 ] || [ $1 == '-h' ] || [ $1 == '--help' ]
then
	echo "Usage : run.sh cmp [argv]"
else
	LD_PRELOAD=`pwd`/$lib $*
fi
