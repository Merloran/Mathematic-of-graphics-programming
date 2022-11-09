#pragma once
#include "corecrt_math_defines.h"
#include <iostream>
#include <cmath>

template <typename Type>
class Vector4
{
public:
	Type X, Y, Z, W;

	Vector4(Type X, Type Y, Type Z, Type W)
		: X(X)
		, Y(Y)
		, Z(Z)
		, W(W)
	{}

	Vector4(Type Value)
		: X(Value)
		, Y(Value)
		, Z(Value)
		, W(Value)
	{}

	Vector4()
		: X((Type)0)
		, Y((Type)0)
		, Z((Type)0)
		, W((Type)0)
	{}


	Vector4 operator+(const Vector4& V)
	{
		return Vector4(this->X + V.X, this->Y + V.Y, this->Z + V.Z, this->W + V.W);
	}

	void operator+=(const Vector4& V)
	{
		this->X += V.X;
		this->Y += V.Y;
		this->Z += V.Z;
	}

	Vector4 operator-(const Vector4& V)
	{
		return Vector4(this->X - V.X, this->Y - V.Y, this->Z - V.Z, this->W - V.W);
	}

	Vector4 operator-()
	{
		return Vector4(-this->X, -this->Y, -this->Z, -this->W);
	}

	void operator-=(const Vector4& V)
	{
		this->X -= V.X;
		this->Y -= V.Y;
		this->Z -= V.Z;
		this->W -= V.W;
	}

	// Multiply by Scalar
	Vector4 operator*(const Type& S)
	{
		return Vector4(this->X * S, this->Y * S, this->Z * S, this->W * S);
	}

	// Multiply by Scalar
	void operator*=(const Type& S)
	{
		this->X *= S;
		this->Y *= S;
		this->Z *= S;
		this->W *= S;
	}

	// Multiply by Vector(Dot)
	Vector4 operator*(const Vector4& V)
	{
		return Vector4(this->X * V.X, this->Y * V.Y, this->Z * V.Z, this->W * V.W);
	}

	// Multiply by Vector(Dot)
	void operator*=(const Vector4& V)
	{
		this->X *= V.X;
		this->Y *= V.Y;
		this->Z *= V.Z;
		this->W *= V.W;
	}

	Vector4 operator/(const Type& S)
	{
		if (S != (Type)0)
		{
			return Vector4(this->X / S, this->Y / S, this->Z / S, this->W / S);
		}
		else
		{
			throw std::logic_error("Cannot divide by 0\n");
		}
	}

	void operator/=(const Type& S)
	{
		if (S != (Type)0)
		{
			this->X /= S;
			this->Y /= S;
			this->Z /= S;
			this->W /= S;
		}
		else
		{
			throw std::logic_error("Cannot divide by 0\n");
		}
	}

	Type Length()
	{
		return sqrt(this->X * this->X
				  + this->Y * this->Y
				  + this->Z * this->Z
				  + this->W * this->W);
	}

	Type LengthSquared()
	{
		return this->X * this->X
			 + this->Y * this->Y
			 + this->Z * this->Z
			 + this->W * this->W;
	}

	// Returns normalized vector
	Vector4 Normalize()
	{
		Type length = this->Length();
		if (length != (Type)0)
		{
			return *this / length;
		}
		else
		{
			throw std::logic_error("Cannot divide by 0\n");
		}
	}

	Type DotProduct(Vector4 V)
	{
		return this->X * V.X + this->Y * V.Y + this->Z * V.Z + this->W * V.W;
	}

	static Type DegToRad(Type Degrees)
	{
		return Degrees * (M_PI / 180.0);
	}

	static Type RadToDeg(Type Radians)
	{
		return Radians * (180.0 / M_PI);
	}


	// Print to console Vector in format (X, Y, Z, W)
	void ToString()
	{
		std::cout << "(" << Round(X) << ", " << Round(Y) << ", " << Round(Z) << ", " << Round(W) << ")\n";
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