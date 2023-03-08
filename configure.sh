#!/bin/sh

BUILD_TYPE=$1
FRESH_BUILD=$2

# Do we have a build type?
if [ -z $BUILD_TYPE ]
then
	BUILD_TYPE="Release"
fi

if [[ $FRESH_BUILD == "fresh" ]]
then
	echo "Making a fresh build"
	
	rm -rf build/*
	
	cmake -DFTXUI_BUILD_DOCS=OFF -DFTXUI_BUILD_EXAMPLES=OFF -DFTXUI_ENABLE_INSTALL=OFF -S . -B build/ --fresh -DCMAKE_BUILD_TYPE=$BUILD_TYPE
else
	cmake -DFTXUI_BUILD_DOCS=OFF -DFTXUI_BUILD_EXAMPLES=OFF -DFTXUI_ENABLE_INSTALL=OFF -S . -B build/ -DCMAKE_BUILD_TYPE=$BUILD_TYPE
fi
