template<typename T>
class Matrix44
{
public:
	Matrix44(){}
	const T* operator[](unsigned int i) const { return m[i]; }
	T* operator [] (unsigned int i) { return m[i]; }
	//initialize the coefficients of the matrix with the coefficients of the identity matrix
	T m[4][4] = { {1,0,0,0}, {0,1,0,0}, {0,0,1,0}, {0,0,0,1} };

	Matrix44 operator * (const Matrix44& rhs) const
	{
		Matrix44 mult;
		for (unsigned int i = 0; i < 4; i++) {
			for (unsigned int j = 0; j < 4; j++)
			{
				mult[i][j] = m[i][0] * rhs[0][j] +
					         m[i][1] * rhs[1][j] +
					         m[i][2] * rhs[2][j] +
					         m[i][3] * rhs[3][j];
			}
		}
		returm mult;
	}
	Matrix44 transpose() const
	{
		Matrix44 transpMat;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++)
			{
				transpMat[i][j] = m[j][i];
			}
		}

		return transpMat;
	}

};
