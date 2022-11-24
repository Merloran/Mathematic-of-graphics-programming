#pragma once
#include "Vector3.h"
#include <iostream>

template <typename Type>
class Quaternion
{
public:
	// W is real part and X,Y,Z are imaginary part(Vector3)
	Type W, X, Y, Z;

	Quaternion(Type W, Type X, Type Y, Type Z)
		: W(W)
		, X(X)
		, Y(Y)
		, Z(Z)
	{}

	Quaternion(Type W, Vector3<Type> V)
		: W(W)
		, X(V.X)
		, Y(V.Y)
		, Z(V.Z)
	{}

	Quaternion(Type Value)
		: W(Value)
		, X(Value)
		, Y(Value)
		, Z(Value)
	{}

	Quaternion()
		: W((Type)1)
		, X((Type)0)
		, Y((Type)0)
		, Z((Type)0)
	{}

	Quaternion operator+(const Quaternion& Q)
	{
		return Quaternion(this->W + Q.W,this->X + Q.X, this->Y + Q.Y, this->Z + Q.Z);
	}

	void operator+=(const Quaternion& Q)
	{
		this->W += Q.W;
		this->X += Q.X;
		this->Y += Q.Y;
		this->Z += Q.Z;
	}

	Quaternion operator-(const Quaternion& Q)
	{
		return Quaternion(this->W - Q.W,this->X - Q.X, this->Y - Q.Y, this->Z - Q.Z);
	}
	
	Quaternion operator-()
	{
		return Quaternion(-this->W, -this->X, -this->Y, -this->Z);
	}

	void operator-=(const Quaternion& Q)
	{
		this->W -= Q.W;
		this->X -= Q.X;
		this->Y -= Q.Y;
		this->Z -= Q.Z;
	}

	Quaternion operator*(const Quaternion& Q)
	{
		Vector3<Type> V1 = this->Imaginary();
		Vector3<Type> V2(Q.X, Q.Y, Q.Z);
		return Quaternion(this->W * Q.W - V1.DotProduct(V2),
						  V2 * this->W + V1 * Q.W + V1.Cross(V2));
	}

	void operator*=(const Quaternion& Q)
	{
		Vector3<Type> V1 = this->Imaginary();
		Vector3<Type> V2(Q.X, Q.Y, Q.Z);
		Quaternion Temp(this->W * Q.W - V1.DotProduct(V2),
						V2 * this->W + V1 * Q.W + V1.Cross(V2));
		this->W = Temp.W;
		this->X = Temp.X;
		this->Y = Temp.Y;
		this->Z = Temp.Z;
	}

	Quaternion operator/(const Quaternion& Q)
	{
		Vector3<Type> V1 = this->Imaginary();
		Vector3<Type> V2(Q.X, Q.Y, Q.Z);
		Type Divider = Q.W * Q.W + V2.DotProduct(V2);
		if (Divider != (Type)0)
		{
			return Quaternion(this->W * Q.W - V1.DotProduct(V2) / Divider,
							 (V2 * -this->W  + V1 * Q.W - V1.Cross(V2)) / Divider);
		}
		else
		{
			throw std::logic_error("Cannot divide by 0\n");
		}
	}

	void operator/=(const Quaternion& Q)
	{
		Vector3<Type> V1 = this->Imaginary();
		Vector3<Type> V2(Q.X, Q.Y, Q.Z);
		Type Divider = Q.W * Q.W + V2.DotProduct(V2);
		if (Divider != (Type)0)
		{
			Quaternion Temp(this->W * Q.W - V1.DotProduct(V2) / Divider,
						   (V2 * -this->W + V1 * Q.W - V1.Cross(V2)) / Divider);
			this->W = Temp.W;
			this->X = Temp.X;
			this->Y = Temp.Y;
			this->Z = Temp.Z;
		}
		else
		{
			throw std::logic_error("Cannot divide by 0\n");
		}
	}
	
	static Vector3<Type> Rotate(Vector3<Type> V, Type Degrees, Vector3<Type> Axis)
	{
		Quaternion Q(cos(Vector3<Type>::DegToRad(Degrees) / (Type)2), Axis * sin(Vector3<Type>::DegToRad(Degrees) / (Type)2) / Axis.Length());

		return (Q * Quaternion((Type)0, V) * Q.Inverse()).Imaginary();
	}

	Quaternion Inverse()
	{
		return Quaternion(this->W, -this->Imaginary());
	}

	Vector3<Type> Imaginary()
	{
		return Vector3<Type>(this->X, this->Y, this->Z);
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