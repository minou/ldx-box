#!/bin/bash
repository=iniparser
address=git://github.com/ndevilla/iniparser.git

if [ ! -d $repository ]
then
    git clone $address
fi

cd $repository/src
patch -p0 < ../../fix-fopen.patch
cd ..
make
