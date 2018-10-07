
//This class generates the velocity distribution of two counter-streaming beams of electrons in a hot unmagnetized
//plasma. It makes use of the acceptance-rejection sampling method.

#ifndef VEL_DIST
#define VEL_DIST

class VelDist
{
private:
	const double pi =  3.1415926;
	const double m = 9.10938356e-31;
	double v_th = 0.;
	int n_0 = 0;
	double v_b = 0.;
	double v_min = 0.;
	double v_max = 0.;
	double v = 0.;

public:
	VelDist();
	~VelDist();

	void setV_th (double);
	void setV_b  (double);
	int setn_0  (int);
	void setVbounds();
	void show();
	double generateV();
	double generateF(double);
	double acceptV(double,double,double);
	void sampleV();
};
#endif
