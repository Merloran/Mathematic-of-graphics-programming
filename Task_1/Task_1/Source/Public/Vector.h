#pragma once
#include "corecrt_math_defines.h"
#include <iostream>
#include <cmath>

template <typename Type>
class Vector3
{
public:
	Type X, Y, Z;

	Vector3(Type X, Type Y, Type Z)
		: X(X)
		, Y(Y)
		, Z(Z)
	{}

	Vector3()
		: X(NULL)
		, Y(NULL)
		, Z(NULL)
	{}


	Vector3 operator+(const Vector3& V)
	{
		return Vector3(this->X + V.X, this->Y + V.Y, this->Z + V.Z);
	}

	void operator+=(const Vector3& V)
	{
		this->X += V.X;
		this->Y += V.Y;
		this->Z += V.Z;
	}

	Vector3 operator-(const Vector3& V)
	{
		return Vector3(this->X - V.X, this->Y - V.Y, this->Z - V.Z);
	}

	Vector3 operator-()
	{
		return Vector3(-this->X, -this->Y, -this->Z);
	}

	void operator-=(const Vector3& V)
	{
		this->X -= V.X;
		this->Y -= V.Y;
		this->Z -= V.Z;
	}

	// Multiply by Scalar
	Vector3 operator*(const Type& S)
	{
		return Vector3(this->X * S, this->Y * S, this->Z * S);
	}

	// Multiply by Scalar
	void operator*=(const Type& S)
	{
		this->X *= S;
		this->Y *= S;
		this->Z *= S;
	}

	// Multiply by Vector(Dot)
	Vector3 operator*(const Vector3& V)
	{
		return Vector3(this->X * V.X, this->Y * V.Y, this->Z * V.Z);
	}

	// Multiply by Vector(Dot)
	void operator*=(const Vector3& V)
	{
		this->X *= V.X;
		this->Y *= V.Y;
		this->Z *= V.Z;
	}

	Vector3 operator/(const Type& S)
	{
		if (S != (Type)0)
		{
			return Vector3(this->X / S, this->Y / S, this->Z / S);
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
				  + this->Z * this->Z);
	}

	Type LengthSquared()
	{
		return this->X * this->X
			 + this->Y * this->Y
			 + this->Z * this->Z;
	}

	// Returns normalized vector
	Vector3 Normalize()
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

	Type DotProduct(Vector3 V)
	{
		return this->X * V.X + this->Y * V.Y + this->Z * V.Z;
	}

	// Returns cross Vector of 2 Vectors
	Vector3 Cross(const Vector3& V)
	{
		return Vector3(this->Y * V.Z - this->Z * V.Y,
					   this->Z * V.X - this->X * V.Z,
					   this->X * V.Y - this->Y * V.X);
	}

	// Returns Angle between two Vectors in Radians
	// Works bad for integer types
	static Type GetAngle(Vector3 V1, Vector3 V2)
	{
		return acos(V1.DotProduct(V2) / (V1.Length() * V2.Length()));
	}

	static Type DegToRad(Type Degrees)
	{
		return Degrees * (M_PI / 180.0);
	}

	static Type RadToDeg(Type Radians)
	{
		return Radians * (180.0 / M_PI);
	}

	
	// Print to console Vector in format (X, Y, Z)
	void ToString()
	{
		std::cout << "(" << X << ", " << Y << ", " << Z << ")\n";
	}
};