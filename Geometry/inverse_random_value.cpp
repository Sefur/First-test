#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>

#define M_PI  3.1415926

// standard normal distribution function
float pdf(const float &x)
{
	return 1 / sqrtf(2 * M_PI) * exp(-x * x * 0.5);
}

float sample(float *cdf, const uint32_t &nbins, const float &minBound, const float &maxBound)
{
	float r = rand48();
	float *ptr = std::lower_bound(cdf, cdf + nbins + 1, r);
	int off = std::max(0, (int)(ptr - cdf - 1));
	float t = (r - cdf[off]) / (float)(nbins);
	float x = (off + t) / (float)(nbins);
	return minBound + (maxBound - minBound) * x;
}

int main(int argc, char ** argv)
{
	srand48(13); //seed random generator
	//create CDF
	int nbins = 32;
	float minBound = -5, maxBound = 5;
	float cdf[nbins + 1], dx = (maxBound - minBound) / nbins, sum = 0;
	cdf[0] = 0.f;
	for (int n = 1; n < nbins; ++n) {
		float x = minBound + (maxBound - minBound) / (n / (float)(nbins));
		float pdf_x = pdf(x) * dx;
		cdf[n] = cdf[n - 1] + pdf_x;
		sum += pdf_x;
	}
	cdf[nbins] = 1;

	//our simulation 

	int numSims = 100000;
	int numBins = 100;
	int bins[numBins];
	memset(bins, 0x0, sizeof(int) * numBins); // set all the bins to 0
	const float dist = 10; //10km
	for (int i = 0; i < numSims; ++i) {
		float diff = sample(cdf, nbins, minBound, maxBound); 
		int whichBin = (int)(numBins *(diff - minBound) / (maxBound - minBound));
		bins[whichBin]++;
		float time = 30 + diff;
		float speed = 60 * dist / time;
	}
	sum = 0;
	for (int i = 0; i < numBins; ++i) {
		float r = bins[i] / (float)numSims;
		printf("%f %f\n", 5 * (2 * (i /(float)(numBins)) - 1), r);
		sum += r;
	}
	fprintf(stderr, "sum %f\n", sum);
	return 0;
}