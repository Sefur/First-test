#include<cstdlib>
#include<cstdio>
#include<random>

int main(int argc, char **argv)
{
	std::default_random_engine gen;
	std::uniform_real_distribution<float> distr;
	int N = (argc == 2) ? atoi(argv[1]) : 1024, hits = 0;
	for (int i = 0; i < N; i++) {
		float x = distr(gen);
		float y = distr(gen);
		float l = sqrt(x*x + y*y);
		if(l <= 1) hits++;
	}
	fprintf(stderr, "Area of unit disk: %f (%d)\n", float(hits) / N * 4, hits);

	return 0;
}