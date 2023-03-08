#!/bin/sh

BUILD_TYPE="$1"

# Do we have a build type?
if [ -z $BUILD_TYPE ]
then
	BUILD_TYPE="Release"
fi
	
cmake -DFTXUI_BUILD_DOCS=OFF -DFTXUI_BUILD_EXAMPLES=OFF -DFTXUI_ENABLE_INSTALL=OFF -DCMAKE_BUILD_TYPE="${BUILD_TYPE}" -G Xcode -T buildsystem=12 -S . -B projects/ --fresh
