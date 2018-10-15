#!/bin/bash
make DEBUG=0&&
./vel_dist &&
python3 plot.py &&
exit

