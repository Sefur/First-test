#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <fstream>
#include <stdint.h>

float evalFunc(const float &x, const float &y, const float &xmax, const float &ymax)
{
	return 1. / 2. + 1. / 2. * powf(1. - y/ymax, 3.) * sin(2. * M_PI * (x/xmax) * exp(8.*(x / xmax)));

}

int main(int argc, char **argv)
{
	int width = 512, height =512;
	int nsamples = 1;
	unsigned char *pixels = new unsigned char[width * height];
	for(int y = 0; y < height; ++y) {
		for(int x = 0; x < width; ++x){
			float sum = 0;
			for(int ny = 0; ny < nsamples; ++ny) {
				for(int nx = 0; nx < nsamples; ++nx){
					#ifdef REGULAR
					sun += evalFunc(x + (nx + 0.5) / nsamples, y + (ny + 0.5) / nsamples, width, height);
					#endif
					#ifdef RANDOM
					sum += evalFunc(x + drand48(), y + drand48(), width, height);
					#endif

				}
			}
			pixels[y * width + x] = (unsigned char)(255 * sum / (nsamples * nsamples));
		}
	}
	std::ofstream ofs;
	ofs.open("./sampling.ppm");
	ofs << "P5\n" << width << " " << height << "\n255\n";
	ofs.write((char*)pixels, width * height);
	ofs.close();
	delete [] pixels;
	return 1;
}