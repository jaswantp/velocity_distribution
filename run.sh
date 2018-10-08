#!/bin/bash
if [ ! -d "./build/make.run.linux.x86_64/build" ]; then
  mkdir -p ./build/make.run.linux.x86_64/
fi
cd ./build/make.run.linux.x86_64/ &&
make -f ../../Makefile BUILD_MODE=run &&
ls &&
./vel_dist &&
cd ../../ &&
python3 plot.py &&
exit

