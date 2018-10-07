#include "vel_dist.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>
VelDist::VelDist()
{
	//set seed, beam velocity, number of ions/electrons and thermal spread.
	srand(time(NULL));
	v_th = 2;
	n_0  = 2000;
	v_b  = 4;
}
VelDist::~VelDist()
{

}
void VelDist::setV_th(double Vth)
{
	v_th = Vth;
}
void VelDist::setV_b(double Vb)
{
	v_b = Vb;
}
int VelDist::setn_0(int n0)
{
	if (n0 < 0)
	{
		std::cout << "Error! number of electrons can't be negative!";
	}
	else
	{
		n_0 = n0;
	}
	return 0;
}
void VelDist::setVbounds()
{
	//v_max = allowable velocity of the farther edge of maxwellian with high velocity.
	//v_min = allowable velocity of the lower edge of maxwellian with low velocity.
	// DO NOT SET THE FACTOR = 1. SET IT SOMEWHERE B/W 1.1 AND 10.
	v_max = 4*v_b;
	v_min = -4*v_b;
}
void VelDist::show()
{
	std::cout << "v_b = " << v_b << std::endl;
	std::cout << "v_max = " << v_max << std::endl;
	std::cout << "v_min = " << v_min << std::endl;
	std::cout << "v_th = " << v_th << std::endl;
	std::cout << "n_0 = " << n_0 << std::endl;

}
double VelDist::generateV()
{
	//generate random velocity b/w v_min and v_max.
	v = v_min + (v_max - v_min)*(double(rand())/double(RAND_MAX));
	//return v;
	return generateF(v);
}
double VelDist::generateF(double v)
{
	double param1 = 1/(2.*pi*v_th*v_th);
	double param2 = -(v-v_b) * (v-v_b)/(v_th * v_th * 2.);
	double param3 = -(v+v_b) * (v+v_b)/(v_th * v_th * 2.);
	double F = (n_0 * 0.5) * sqrt(param1) * (exp(param2) + exp(param3)) ;

	//FMAX at v = +v_b or -v_b.
	double F_MAX = (n_0 * 0.5) * sqrt(param1) * (1 + exp(double((-2. * v_b * v_b)/(v_th*v_th))));

	//generate random w within 0, F_MAX.
	double w =  F_MAX * (double(rand())/double(RAND_MAX));
	return acceptV(w,v,F);
}
double VelDist::acceptV(double w, double v, double F)
{
	//acceptance of v.
	if (w < F)
	{
		std::cout << F << ",";
		return v;
	}
	//Rejection and regenerate v.
	else
	{
		return generateV();
	}
}
void VelDist::sampleV()
{
	double i;
	for (i = 1 ; i <= n_0 ; ++i)
	{
		std::cout << generateV() << std::endl;
	}
}




















