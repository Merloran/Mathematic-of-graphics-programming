#include "Source/Public/Quaternion.h"
#include <iostream>
typedef Vector3<float> Vec3f;
typedef Vector3<double> Vec3;
typedef Quaternion<double> Quat;
typedef Quaternion<float> Quatf;

int main()
{
	//==========ADD==========
	{
		Quat Q1(1.0);
		Quat Q2(2.0);
		std::cout << "==========ADD==========" << std::endl;
		Q1.ToString();
		std::cout << "+" << std::endl;
		Q2.ToString();
		std::cout << "=" << std::endl;
		Quat Result = Q1 + Q2;
		Result.ToString();
		Q1 += Q2;
		Q1.ToString();
		std::cout << std::endl;
	}
	//==========SUBSTRACT==========
	{
		Quat Q1(1.0);
		Quat Q2(2.0);
		std::cout << "==========SUBSTRACT==========" << std::endl;
		Q1.ToString();
		std::cout << "-" << std::endl;
		Q2.ToString();
		std::cout << "=" << std::endl;
		Quat Result = Q1 - Q2;
		Result.ToString();
		Q1 -= Q2;
		Q1.ToString();
		std::cout << std::endl;
	}
	//==========MULTIPLY==========
	{
		Quat Q1(1.0);
		Quat Q2(2.0);
		std::cout << "==========MULTIPLY==========" << std::endl;
		Q1.ToString();
		std::cout << "*" << std::endl;
		Q2.ToString();
		std::cout << "=" << std::endl;
		Quat Result = Q1 * Q2;
		Result.ToString();
		Q1 *= Q2;
		Q1.ToString();
		std::cout << std::endl;
	}
	//==========DIVIDE==========
	{
		Quat Q1(1.0);
		Quat Q2(2.0);
		std::cout << "==========DIVIDE==========" << std::endl;
		Q1.ToString();
		std::cout << "/" << std::endl;
		Q2.ToString();
		std::cout << "=" << std::endl;
		Quat Result = Q1 / Q2;
		Result.ToString();
		Q1 /= Q2;
		Q1.ToString();
		std::cout << std::endl;
	}
	//==========ROTATE==========
	{
		Vec3 V(-1.0);
		double Angle = 270.0;
		Vec3 Axis(1.0, 0.0, 0.0);
		std::cout << "==========ROTATE==========" << std::endl;
		V.ToString();
		std::cout << "Rotated by " << Angle << " degrees, around" << std::endl;
		Axis.ToString();
		std::cout << "=" << std::endl;
		Vec3 Result = Quat::Rotate(V, 270.0, Axis);
		Result.ToString();
		std::cout << std::endl;
	}
	//==========COMUTATIVITY==========
	{
		Quat Q1(2.0, 1.0, 2.0, 1.0);
		Quat Q2(3.0);
		std::cout << "==========COMUTATIVITY==========" << std::endl;
		Q1.ToString();
		std::cout << "*" << std::endl;
		Q2.ToString();
		std::cout << "=" << std::endl;
		Quat Result = Q1 * Q2;
		Result.ToString();
		std::cout << "Reversed" << std::endl;
		Q2.ToString();
		std::cout << "*" << std::endl;
		Q1.ToString();
		std::cout << "=" << std::endl;
		Result = Q2 * Q1;
		Result.ToString();
		std::cout << std::endl;
	}

	return 0;
}