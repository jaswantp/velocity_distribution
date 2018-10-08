#!/bin/bash
cd ./build/make.run.linux.x86_64/ &&
make -f ../../Makefile BUILD_MODE=run clean &&
exit
