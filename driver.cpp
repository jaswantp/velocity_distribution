#include "vel_dist.hpp"
#include "file_io.hpp"
#include <iostream>

int main(int argc, char **argv) {
	VelDist VelDist;
	FileIO file;
	VelDist.setVbounds();
	VelDist.show();
	VelDist.sampleV();
	for (int i = 1; i <= VelDist.getN(); ++i)
	{
		file.fileWrite(VelDist.getF(i), VelDist.getV(i), VelDist.getX(i));
	}
	return 0;
}
