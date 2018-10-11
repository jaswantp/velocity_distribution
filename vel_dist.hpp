
//This class generates the velocity distribution of two counter-streaming beams of electrons in a hot unmagnetized
//plasma. It makes use of the acceptance-rejection sampling method.

#ifndef VEL_DIST
#define VEL_DIST

class VelDist
{
private:
	const double pi =  3.1415926;
	const double m = 9.10938356e-31;
	double v_th = 2.;
	double L = 2;
	int n_0 = 20000;
	double v_b = 5.;
	double v_min = 0.;
	double v_max = 0.;
	double* pX = nullptr;
	double* pV = nullptr;
	double* pF = nullptr;

public:
	VelDist();
	~VelDist();

	//Getters.
	int getN();
	double getF(int);
	double getV(int);
	double getX(int);

	//Setters.
	void setV_th (double);
	void setV_b  (double);
	int setn_0  (int);
	void setVbounds();

	//General functions
	void show();
	void sampleV();
	double generateV(int);
	double generateF(double, int);
	double acceptV(double,double,double,int);

};
#endif
