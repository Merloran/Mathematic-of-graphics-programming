#include "Source/Public/Quaternion.h"
#include "Source/Public/Matrix.h"
#include <iostream>
typedef Vector3<float> Vec3f;
typedef Vector3<double> Vec3;
typedef Quaternion<double> Quat;
typedef Quaternion<float> Quatf;
typedef Matrix<double, 3, 3> Mat3;

int main()
{
	{
		/*******************/
		/*****Zadanie_1*****/
		/*******************/
		// L1:
		// x = -2 +  3t
		// y =  5 +  1t
		// z =  0 +  5t
		//
		// L2:
		// x = -2 +  1t
		// y =  4 +  5t
		// z =  0 +  3t

		std::cout << "*****Zadanie 1*****" << std::endl;
		Vec3 P0(-2.0,  4.0,  0.0);
		Vec3 V0( 3.0,  1.0,  5.0);

		Vec3 P1(-2.0,  4.0,  0.0);
		Vec3 V1( 1.0, -5.0,  3.0);
		if (V0.Cross(V1).LengthSquared() != 0.0)
		{
			double t0 = (P0 - P1).Cross(V1).DotProduct(V0.Cross(V1)) / V0.Cross(V1).LengthSquared();
			(P0 + V0 * t0).ToString();
		}
		else
		{
			std::cout << "Lines are not intersecting!" << std::endl;
		}

		/*******************/
		/*****Zadanie_2*****/
		/*******************/
		std::cout << "*****Zadanie 2*****" << std::endl;
		std::cout << Vec3::RadToDeg(Vec3::GetAngle(V0, V1)) << std::endl;
	}

	{
		/*******************/
		/*****Zadanie_3*****/
		/*******************/
		// L:
		// x = -2 + 3t
		// y =  2 - 1t
		// z = -1 + 2t
		// P:
		// 2x + 3y + 3z - 8 = 0

		std::cout << "*****Zadanie 3*****" << std::endl;
		Vec3 P(-2.0,  2.0, -1.0);
		Vec3 V( 3.0, -1.0,  2.0);

		Vec3 N( 2.0,  3.0,  3.0);
		Vec3 Q( 1.0,  1.0,  1.0); // Chosen point on a plane P
		if (N.DotProduct(V) != 0.0)
		{
			double t = -N.DotProduct(P - Q) / N.DotProduct(V);
			(P + V * t).ToString();
		}
		else
		{
			std::cout << "Objects are not intersecting!" << std::endl;
		}

		/*******************/
		/*****Zadanie_4*****/
		/*******************/
		std::cout << "*****Zadanie 4*****" << std::endl;
		std::cout << Vec3::RadToDeg(Vec3::GetAngle(V, N)) << std::endl;
	}

	{
		/*******************/
		/*****Zadanie_5*****/
		/*******************/
		// P1:
		// 2x - 1y + 1z - 8 = 0
		// P2:
		// 4x + 3y + 1z + 14 = 0

		std::cout << "*****Zadanie 5*****" << std::endl;
		Vec3 N1( 2.0, -1.0,  1.0);
		Vec3 Q1( 4.0,  1.0,  1.0); // Chosen point on a plane P1

		Vec3 N2( 4.0,  3.0,  1.0);
		Vec3 Q2( 1.0,  1.0, -21.0); // Chosen point on a plane P2

		Vec3 V = N1.Cross(N2);

		float Divisior = V.LengthSquared();
		if (Divisior != 0.0)
		{
			double D1 = -Q1.DotProduct(N1); // -8
			double D2 = -Q2.DotProduct(N2); // 14

			Vec3 P = ((V.Cross(N2) * D1) + (N1.Cross(V) * D2)) / Divisior;
			std::cout << "P: "; P.ToString();
			std::cout << "V: "; V.ToString();
		}
		else
		{
			std::cout << "Planes are not intersecting!" << std::endl;
		}

		/*******************/
		/*****Zadanie_6*****/
		/*******************/
		std::cout << "*****Zadanie 6*****" << std::endl;
		std::cout << Vec3::RadToDeg(Vec3::GetAngle(N1, N2)) << std::endl;
	}

	{
		/*******************/
		/*****Zadanie_7*****/
		/*******************/
		// A  = ( 5,  5,  4)
		// A' = ( 10,  10,  6)
		// B  = ( 5,  5,  5)
		// B' = ( 10,  10,  3)

		std::cout << "*****Zadanie 7*****" << std::endl;
		Vec3 A0(5.0, 5.0, 4.0);
		Vec3 A1(10.0, 10.0, 6.0);

		Vec3 B0(5.0, 5.0, 5.0);
		Vec3 B1(10.0, 10.0, 3.0);

		Vec3 VA = A1 - A0;
		Vec3 VB = B1 - B0;

		Vec3 W = B0 - A0;

		Vec3 N = -VA.Cross(W);
		if ((B1 - A0).DotProduct(N) == 0.0)
		{
			Vec3 N1 = VA.Cross(N);
			Vec3 N2 = VB.Cross(N);

			if ((A0 - B0).DotProduct(N2) < 0.0 && (A1 - B0).DotProduct(N2) > 0.0
				&& (B0 - A0).DotProduct(N1) > 0.0 && (B1 - A0).DotProduct(N1) < 0.0)
			{
				double t0 = (A0 - B0).Cross(VA).DotProduct(VA.Cross(VB)) / VA.Cross(VB).LengthSquared();
				(A0 - VA * t0).ToString();
			}
			else
			{
				std::cout << "Points are not intersecting." << std::endl;
			}
		}
		else
		{
			std::cout << "Points are not lie in a plane" << std::endl;
		}


	}

	{
		/*******************/
		/*****Zadanie_8*****/
		/*******************/
		// C  = ( 0,  0,  0)
		// R  = sqrt(26)
		// A  = ( 3, -1, -2)
		// A' = ( 5,  3, -4)

		std::cout << "*****Zadanie 8*****" << std::endl;
		Vec3 C( 0,  0,  0);
		double R2 = 26.0;
		Vec3 A0( 3, -1, -2);
		Vec3 A1( 5,  3, -4);

		Vec3 V = (A1 - A0).Normalize();
		Vec3 W = C - A0;

		double L1 = V.DotProduct(W);
		double a1Squared = W.LengthSquared() - L1 * L1;
		double d1Squared = R2 - a1Squared;

		double L2 = (-V).DotProduct(W);
		double a2Squared = W.LengthSquared() - L2 * L2;
		double d2Squared = R2 - a2Squared;

		if (d1Squared > 0.0 && d2Squared > 0.0)
		{
			std::cout << "Objects are intersecting at points:" << std::endl;
			Vec3 P1 = A0 + V * (L1 - sqrt(d1Squared));
			P1.ToString();
			Vec3 P2 = A0 - V * (L2 - sqrt(d2Squared));
			P2.ToString();
		}
		else
		{
			std::cout << "Objects are not intersecting!" << std::endl;
		}


	}

	return 0;
}