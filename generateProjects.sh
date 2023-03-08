#!/bin/sh

BUILD_TYPE=$1
TARGET=$2

if [ -z $TARGET ]
then
	echo "\nThis script generates project files for different IDEs"
	echo "Usage:"
	echo "\tgenerateProjects.sh BuildType IDE"
	echo "\nBuildType: Debug, Release"
	echo "IDE: Xcode, VisualStudio"
	echo "\nExample: generateProjects.sh Debug Xcode"
fi

cmake -DFTXUI_BUILD_DOCS=OFF -DFTXUI_BUILD_EXAMPLES=OFF -DFTXUI_ENABLE_INSTALL=OFF -S . -B build/ --fresh -DCMAKE_BUILD_TYPE=$BUILD_TYPE -G $TARGET -T buildsystem=12
