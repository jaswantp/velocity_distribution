#include "vel_dist.hpp"
#include "file_io.hpp"
#include <iostream>

int main(int argc, char **argv) {
	//Init instances of VelDist and FileIO
	VelDist plasma;
	FileIO file;
	plasma.setVbounds();
	plasma.show();
	plasma.sampleV();
	file.fileWrite("f(v), ","v, ","x");
	for (int i = 1; i <= plasma.getN(); ++i)
	{
		file.fileWrite(plasma.getF(i), plasma.getV(i), plasma.getX(i));
	}
	return 0;
}
