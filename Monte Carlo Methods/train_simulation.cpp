#include<cstdlib>
#include<cstdio>
#include "drand48.h"

float pdf(const float &x)
{return 1 / sqrt(2 * M_PI) * exp(-x*x*0.5);}


int main(int argc, char ** argv)
{
	srand48(13); // intialize uniform random variable
	int numSims = 10;
	const float dist = 10;
	for (int i = 0; i < numSims; ++i){

        printf("%f",drand48());
	    float time =25 + drand48() * 10; // [25, 35]
	    float speed = 60* dist / time ;
	    printf("Train travel at speed: %f\n", speed);
	}
	return 0;
   
    // get the CDF from PDF----------------------
	int nbins = 32;
	float minBound = -5, maxBound = 5;
	float cdf[nsamples + 1], dx = (maxBound - minBound) / nbins, sum = 0;
	cdf[0] = 0.f;
	for(int n = 1; n < nbins; ++n) {
		float x = minBound + (maxBound - minBound) * (n / (float)(nbins));
		float pdf_x = pdf(x) * dx;
		cdf[n] = cdf[n - 1] + pdf_x;
		sum += pdf_x;
	}
	cdf[nbins] = 1;
	printf("sum %f\n", sum);
	for (int n = 0; n < nsamples + 1; ++n) {
		printf("%f %f\n", minBound + (maxBound - minBound) * (n / (float)(nbins)), cdf[n]);
	}
	//--------------------------------------------
}  

