#include "vel_dist.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>
VelDist::VelDist()
{
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
	v_max = 3.*v_b;
	v_min = -3.*v_b;
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
	double F_MAX = (n_0 * 0.5) * sqrt(param1) * (1 + exp(double((-2. * v_b * v_b)/(v_th*v_th))));
	double w =  F_MAX * (double(rand())/double(RAND_MAX));
	return acceptV(w,v,F);
}
double VelDist::acceptV(double w, double v, double F)
{
	if (w < F)
	{
		std::cout << F << ",";
		return v;
	}
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




















