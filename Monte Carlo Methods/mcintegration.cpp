

unsigned int N = 32;

inline float linerp(const float *f, const short &i, const float &t, const int &max)
{ return f[i] * (1 - t) + f[std::min(max, i+1)] * t; }

void monteCarloIntegration(const short &curveIndex, float &X, float &Y, float &Z)
{
	float S = 0; //sum , used to normalize XYZ values
	for (int i = 0; i < N; ++i){
		float lambda = drand48() * (lambdaMax - lambdaMin);
		float b = lambda / 10;
		short j = (short)b;
		float t = b - j;
		//interpolate
		float fx = linerp(spd[curveIndex], j, t, nbins - 1);
		b = lambda / 5;
		j = (short)b;
		t = b - j;
		X += linerp(CIE_X, j, t, 2*nbins - 1) * fx;
        Y += linerp(CIE_Y, j, t, 2*nbins - 1) * fx;
        Z += linerp(CIE_Z, j, t, 2*nbins - 1) * fx;
        S += linerp(CIE_Y, j, t, 2*nbins -1);
	}
	//sum, normalization factor
	S *= (lambdaMax - lambdaMin) / N / S;
	X *= (lambdaMax - lambdaMin) / N / S;
	Y *= (lambdaMax - lambdaMin) / N / S;
	Z *= (lambdaMax - lambdaMin) / N / S;
}

std::uniform_int_distribution<int> distribution(0, 99);
std::mt19937 engine; // MErsennne twister MT19937