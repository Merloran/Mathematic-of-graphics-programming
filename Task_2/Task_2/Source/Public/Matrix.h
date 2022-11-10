#pragma once
#include <iostream>
#include <vector>
#include "./Vector3.h"
#include "./Vector4.h"

typedef unsigned int uint32;

template<typename Type, uint32 Rows, uint32 Cols>
class Matrix
{
public:
	Type** Elements;
	uint32 XSize, YSize;

	/** Creates matrix filled of zeros */
	Matrix()
		: XSize(Rows)
		, YSize(Cols)
	{
		Elements = new Type*[XSize];
		for (uint32 i = (uint32)0; i < XSize; ++i)
		{
			Elements[i] = new Type[YSize];
		}

		for (uint32 x = (uint32)0; x < XSize; ++x)
		{
			for (uint32 y = (uint32)0; y < YSize; ++y)
			{
				Elements[x][y] = (Type)0;
			}
		}
	}

	/** Creates diagonal matrix, identity matrix for value = 1 */
	Matrix(Type Value)
		: XSize(Rows)
		, YSize(Cols)
	{
		Elements = new Type * [XSize];
		for (uint32 i = (uint32)0; i < XSize; ++i)
		{
			Elements[i] = new Type[YSize];
		}

		for (uint32 x = (uint32)0; x < XSize; ++x)
		{
			for (uint32 y = (uint32)0; y < YSize; ++y)
			{
				if (x == y)
				{
					Elements[x][y] = Value;
				}
				else
				{
					Elements[x][y] = (Type)0;
				}
			}
		}
	}

	Matrix(Type Values[Rows][Cols])
		: XSize(Rows)
		, YSize(Cols)
	{
		Elements = new Type * [XSize];
		for (uint32 i = (uint32)0; i < XSize; ++i)
		{
			Elements[i] = new Type[YSize];
		}

		for (uint32 x = (uint32)0; x < XSize; ++x)
		{
			for (uint32 y = (uint32)0; y < YSize; ++y)
			{
				Elements[x][y] = Values[x][y];
			}
		}
	}

	Matrix(Type** Values)
		: XSize(Rows)
		, YSize(Cols)
	{
		Elements = Values;
	}

	Matrix(Matrix&& Other) noexcept
		: Elements(Other.Elements)
		, XSize(Other.XSize)
		, YSize(Other.YSize)
	{
		Other.Elements = nullptr;
	}

	Matrix(const Matrix& Other)
		: Elements(Other.Elements)
		, XSize(Other.XSize)
		, YSize(Other.YSize)
	{
		const_cast<Matrix&>(Other).Elements = nullptr;
	}

	~Matrix()
	{
		if (Elements != nullptr)
		{
			for (uint32 i = 0; i < XSize; ++i)
			{
				delete[] Elements[i];
			}
			delete[] Elements;
			Elements = nullptr;
		}
	}


	Matrix& operator=(Matrix& Other)
	{
		if (this != &Other)
		{
			this->~Matrix();
			std::swap(Elements, Other.Elements);
			std::swap(XSize, Other.XSize);
			std::swap(YSize, Other.YSize);
		}
		return *this;
	}

	Matrix& operator=(Matrix&& Other) noexcept
	{
		if (this != &Other)
		{
			this->~Matrix();
			std::swap(Elements, Other.Elements);
			std::swap(XSize, Other.XSize);
			std::swap(YSize, Other.YSize);
		}
		return *this;
	}

	Type* operator[](uint32 Index)
	{
		return Elements[Index];
	}

	Matrix operator+(const Matrix& M)
	{
		Matrix Temp;
		for (uint32 x = (uint32)0; x < XSize; ++x)
		{
			for (uint32 y = (uint32)0; y < YSize; ++y)
			{
				Temp[x][y] = M.Elements[x][y] + this->Elements[x][y];
			}
		}
		return Temp;
	}

	void operator+=(const Matrix& M)
	{
		for (uint32 x = (uint32)0; x < XSize; ++x)
		{
			for (uint32 y = (uint32)0; y < YSize; ++y)
			{
				this->Elements[x][y] += M.Elements[x][y];
			}
		}
	}

	Matrix operator-()
	{
		Matrix Temp;
		for (uint32 x = (uint32)0; x < XSize; ++x)
		{
			for (uint32 y = (uint32)0; y < YSize; ++y)
			{
				Temp[x][y] = -this->Elements[x][y];
			}
		}
		return Temp;
	}

	Matrix operator-(const Matrix& M)
	{
		Matrix Temp;
		for (uint32 x = (uint32)0; x < XSize; ++x)
		{
			for (uint32 y = (uint32)0; y < YSize; ++y)
			{
				Temp[x][y] = M.Elements[x][y] - this->Elements[x][y];
			}
		}
		return Temp;
	}

	void operator-=(const Matrix& M)
	{
		for (uint32 x = (uint32)0; x < XSize; ++x)
		{
			for (uint32 y = (uint32)0; y < YSize; ++y)
			{
				this->Elements[x][y] -= M.Elements[x][y];
			}
		}
	}

	Matrix operator*(const Type& S)
	{
		Matrix Temp;
		for (uint32 x = (uint32)0; x < XSize; ++x)
		{
			for (uint32 y = (uint32)0; y < YSize; ++y)
			{
				Temp[x][y] = this->Elements[x][y] * S;
			}
		}
		return Temp;
	}

	void operator*=(const Type& S)
	{
		for (uint32 x = (uint32)0; x < XSize; ++x)
		{
			for (uint32 y = (uint32)0; y < YSize; ++y)
			{
				this->Elements[x][y] *= S;
			}
		}
	}

	Matrix operator*(const Matrix& M)
	{
		Matrix Temp;

		if (YSize != M.XSize)
		{
			std::cout << "Cannot multiply matrix " << XSize << "x" << YSize << " by matrix " << M.XSize << "x" << M.YSize << "!" << std::endl;
			return Matrix();
		}

		for (uint32 x = (uint32)0; x < XSize; ++x)
		{
			for (uint32 y = (uint32)0; y < M.YSize; ++y)
			{
				for (uint32 i = (uint32)0; i < YSize; ++i)
				{
					Temp[x][y] += this->Elements[x][i] * M.Elements[i][y];
				}
			}
		}
		return Temp;
	}

	void operator*=(const Matrix& M)
	{
		Matrix Temp;

		if (YSize != M.XSize)
		{
			std::cout << "Cannot multiply matrix " << XSize << "x" << YSize << " by matrix " << M.XSize << "x" << M.YSize << "!" << std::endl;
			return;
		}

		for (uint32 x = (uint32)0; x < XSize; ++x)
		{
			for (uint32 y = (uint32)0; y < M.YSize; ++y)
			{
				for (uint32 i = (uint32)0; i < YSize; ++i)
				{
					Temp[x][y] += this->Elements[x][i] * M.Elements[i][y];
				}
			}
		}
		*this = Temp;
	}

	// Still in experimental phase xD
	Matrix Multiply(const Matrix<Type, Rows, Cols>& M1, const Matrix<Type, Cols, Rows>& M2)
	{

		Type** Values = new Type * [M1.XSize];
		for (uint32 i = (uint32)0; i < M1.XSize; ++i)
		{
			Values[i] = new Type[M2.YSize];
		}

		Matrix Temp = Matrix(Values);
		Temp.XSize = M1.XSize;
		Temp.YSize = M2.YSize;

		if (M1.YSize != M2.XSize)
		{
			std::cout << "Cannot multiply matrix " << M1.XSize << "x" << M1.YSize << " by matrix " << M2.XSize << "x" << M2.YSize << "!" << std::endl;
			return;
		}

		for (uint32 x = (uint32)0; x < M1.XSize; ++x)
		{
			for (uint32 y = (uint32)0; y < M2.YSize; ++y)
			{
				for (uint32 i = (uint32)0; i < M1.YSize; ++i)
				{
					Temp[x][y] += M1.Elements[x][i] * M2.Elements[i][y];
				}
			}
		}
		return Temp;
	}

	void Transpose()
	{
		for (uint32 x = (uint32)0; x < XSize; ++x)
		{
			for (uint32 y = (uint32)0; y < YSize; ++y)
			{
				if (y > x)
				{
					std::swap(Elements[x][y], Elements[y][x]);
				}
			}
		}
	}

	static Type Determinant(const Matrix& M)
	{
		if (M.XSize == 1)
		{
			return M.Elements[0][0];
		}
		Type Result = (Type)0;
		for (uint32 i = (uint32)0; i < M.XSize; ++i)
		{
			Result += (Type)(i % 2 ? -1 : 1) * M.Elements[i][(uint32)0] * Determinant(Reshape(M, i, (uint32)0));
		}

		return Result;
	}

	static Matrix Cofactor(const Matrix& M)
	{
		Matrix Result;
		for (uint32 x = (uint32)0; x < M.XSize; ++x)
		{
			for (uint32 y = (uint32)0; y < M.XSize; ++y)
			{
				Result[x][y] = (Type)((x + y) % 2 ? -1 : 1) * Determinant(Reshape(M, x, y));
			}
		}
		return Result;
	}

	static Matrix Inverse(const Matrix& M)
	{
		Type det = Determinant(M);
		if (det == (Type)0)
		{
			std::cout << "Matrix is singular, cannot calculate inverse matrix" << std::endl;
			return Matrix();
		}

		Matrix TAD = Cofactor(M);
		TAD.Transpose();

		Matrix Result;
		for (uint32 x = (uint32)0; x < M.XSize; ++x)
		{
			for (uint32 y = (uint32)0; y < M.XSize; ++y)
			{
				Result[x][y] = TAD[x][y] / det;
			}
		}

		return Result;
	}

	/** Print all matrix elements */
	void ToString()
	{
		for (uint32 x = (uint32)0; x < XSize; ++x)
		{
			for (uint32 y = (uint32)0; y < YSize; ++y)
			{
				std::cout << Round(Elements[x][y]) << " ";
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}

	/** Translate Matrix 4x4 by Vector3 */
	void Translate(const Vector3<Type>& V)
	{
		if (XSize != 4 || YSize != 4)
		{
			std::cout << "Incorrect Matrix size!" << std::endl;
			return;
		}
		Elements[0][3] = V.X;
		Elements[1][3] = V.Y;
		Elements[2][3] = V.Z;
	}

	/** Scale Matrix 4x4 by Vector3 */
	void Scale(const Vector3<Type>& V)
	{
		if (XSize != 4 || YSize != 4)
		{
			std::cout << "Incorrect Matrix size!" << std::endl;
			return;
		}
		Elements[0][0] *= V.X;
		Elements[1][1] *= V.Y;
		Elements[2][2] *= V.Z;
	}

	/** Rotate Matrix 4x4 about Vector3 */
	void Rotate(Type Degrees, Vector3<Type> V)
	{
		if (XSize != 4 || YSize != 4)
		{
			std::cout << "Incorrect Matrix size!" << std::endl;
			return;
		}
		Vector3<Type> Axis = V.Normalize();

		Type SinAngle = (Type)sin(Axis.DegToRad(Degrees));
		Type CosAngle = (Type)cos(Axis.DegToRad(Degrees));
		Type OneMinusCosAngle = (Type)1 - CosAngle;

		Elements[0][0] = (Axis.X * Axis.X + CosAngle * (1 - Axis.X * Axis.X));
		Elements[0][1] = (Axis.X * Axis.Y * OneMinusCosAngle - SinAngle * Axis.Z);
		Elements[0][2] = (Axis.X * Axis.Z * OneMinusCosAngle + SinAngle * Axis.Y);

		Elements[1][0] = (Axis.X * Axis.Y * OneMinusCosAngle + SinAngle * Axis.Z);
		Elements[1][1] = (Axis.Y * Axis.Y + CosAngle * (1 - Axis.Y * Axis.Y));
		Elements[1][2] = (Axis.Y * Axis.Z * OneMinusCosAngle - SinAngle * Axis.X);

		Elements[2][0] = (Axis.X * Axis.Z * OneMinusCosAngle - SinAngle * Axis.Y);
		Elements[2][1] = (Axis.Y * Axis.Z * OneMinusCosAngle + SinAngle * Axis.X);
		Elements[2][2] = (Axis.Z * Axis.Z + CosAngle * (1 - Axis.Z * Axis.Z));
	}

	/** Multiply matrix by Vector4 */
	Vector4<Type> operator*(const Vector4<Type>& V)
	{
		if (XSize != 4 || YSize != 4)
		{
			std::cout << "Incorrect Matrix size!" << std::endl;
			return Vector4<Type>();
		}

		Vector4<Type> Temp;

		Temp.X = Elements[0][0] * V.X + Elements[0][1] * V.Y + Elements[0][2] * V.Z + Elements[0][3] * V.W;
		Temp.Y = Elements[1][0] * V.X + Elements[1][1] * V.Y + Elements[1][2] * V.Z + Elements[1][3] * V.W;
		Temp.Z = Elements[2][0] * V.X + Elements[2][1] * V.Y + Elements[2][2] * V.Z + Elements[2][3] * V.W;
		Temp.W = Elements[3][0] * V.X + Elements[3][1] * V.Y + Elements[3][2] * V.Z + Elements[3][3] * V.W;

		return Temp;
	}

private:
	static Matrix Reshape(const Matrix& M, uint32 Row, uint32 Col)
	{
		Type** Values = new Type*[M.XSize - 1];
		for (uint32 i = (uint32)0; i < M.XSize - 1; ++i)
		{
			Values[i] = new Type[M.YSize - 1];
		}
		for (uint32 x = (uint32)0, TempX = (uint32)0; x < M.XSize; ++x, ++TempX)
		{
			if (x == Row)
			{
				--TempX;
				continue;
			}

			for (uint32 y = (uint32)0, TempY = (uint32)0; y < M.XSize; ++y, ++TempY)
			{
				if (y == Col)
				{
					--TempY;
					continue;
				}
				Values[TempX][TempY] = M.Elements[x][y];
			}
		}

		Matrix Result(Values);

		Result.XSize = M.XSize - 1;
		Result.YSize = M.YSize - 1;

		return Result;
	}

	Type Round(Type Value, Type Precision = (Type)0.000001)
	{
		if (Precision == (Type)0)
		{
			Precision = (Type)1;
		}
		return std::round(Value / Precision) * Precision;
	}

};