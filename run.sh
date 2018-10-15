#!/bin/bash
make &&
./vel_dist &&
python3 plot.py &&
exit

