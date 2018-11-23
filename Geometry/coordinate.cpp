#include<iostream>

using namespace std;

template<typename T>
class Vec3
{
public:
	//3 most basic ways to initialing a vector
	Vec3() :x(T(0)), y(T(0)), z(T(0)) {};
	Vec3(const T &xx) :x(xx), y(xx), z(xx) {};
	Vec3(T xx, T yy, T zz) :x(xx), y(yy), z(zz) {};
	T x, y, z;

	// length
	T length()
	{
		return sqrt(x*x + y*y + z*z);
	}
	
	// normalize
	Vec3<T>& normalize()
	{
		T len = length();
		if (len > 0) {
			T invLen = 1 / len;
			x *= invLen, y *= invLen, z *= invLen;
		}

		return *this;
	}

	//dot product
	T dot(const Vec3<T> &v) const
	{
		return x * v.x + y * v.y + z * v.z;
	}

	//cross
	Vec3<T> cross(const Vec3<T> &v) const
	{
		return Vec3<T>(
			y * v.z - z * v.y,
			z * v.x - x * v.z,
			x * v.y - y * v.x
			);
	}

	//addition and subtraction
	Vec3<T> operator + (const Vec3<T> &v) const
	{
		return Vec3<T>(x + v.x, y + v.y, z + v.z);
	}
	Vec3<T> operator - (const Vec3<T> &v) const
	{
		return Vec3<T>(x - v.x, y - v.y, z - v.z);
	}
	Vec3<T> operator * (const T &r) const
	{
		return Vec3(x * r, y * r, z * r);
	}
};