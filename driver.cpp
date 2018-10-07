#include "vel_dist.hpp"
int main(int argc, char **argv) {
	VelDist VelDist;
	VelDist.setVbounds();
	VelDist.show();
	VelDist.sampleV();
	return 0;
}
