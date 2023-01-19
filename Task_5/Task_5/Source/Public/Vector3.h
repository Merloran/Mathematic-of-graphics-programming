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

	Vector3(Type Value)
		: X(Value)
		, Y(Value)
		, Z(Value)
	{}

	Vector3()
		: X((Type)0)
		, Y((Type)0)
		, Z((Type)0)
	{}

	friend std::ostream& operator<<(std::ostream& os, Vector3<Type>& V)
	{
		os << "(" << V.Round(V.X) << ", " << V.Round(V.Y) << ", " << V.Round(V.Z) << ")";
		return os;
	}

	bool operator==(const Vector3& V)
	{
		if (V.X == X && V.Y == Y && V.Z == Z)
		{
			return true;
		}
		return false;
	}

	bool operator!=(const Vector3& V)
	{
		if (V.X == X && V.Y == Y && V.Z == Z)
		{
			return false;
		}
		return true;
	}

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
		return Degrees * ((Type)M_PI / (Type)180.0);
	}

	static Type RadToDeg(Type Radians)
	{
		return Radians * ((Type)180.0 / (Type)M_PI);
	}

	
	// Print to console Vector in format (X, Y, Z)
	void ToString()
	{
		std::cout << "(" << Round(X) << ", " << Round(Y) << ", " << Round(Z) << ")\n";
	}


	Type Round(Type Value, Type Precision = (Type)0.000001)
	{
		if (Precision == (Type)0)
		{
			Precision = (Type)1;
		}
		return std::round(Value / Precision) * Precision;
	}

	static Vector3 INVALID()
	{
		return Vector3<Type>(Type(UINT64_MAX), Type(UINT64_MAX), Type(UINT64_MAX));
	}

	Vector3 operator !()
	{
		return INVALID();
	}
};


typedef Vector3<float> Vec3f;