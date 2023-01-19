//#pragma once
//#include "Vector3.h"
//#include "LineExp.h"
//
//template <typename Type>
//class Plane
//{
//public:
//	Vector3<Type> N; //Normal to plane
//	Vector3<Type> P; //Point on plane
//
//	Plane(Vector3<Type> N, Vector3<Type> P)
//		: N(N)
//		, P(P)
//	{}
//
//
//	Line<Type> Intersect(Plane<Type>& P)
//	{
//		Vector3<Type> V = N.Cross(P.N);
//		Type Divisior = V.LengthSquared();
//		if (Divisior != 0.0f)
//		{
//			Type D1 = -this->P.DotProduct(N);
//			Type D2 = -P.P.DotProduct(P.N);
//
//			return Line<Type>(V, ((N.Cross(P.N) * D1) + (N.Cross(V) * D2)) / Divisior);
//		}
//		return Line<Type>::INVALID();
//	}
//
//	Type GetAngle(Plane<Type>& P)
//	{
//		return Vector3<Type>::RadToDeg(Vector3<Type>::GetAngle(N, P.N));
//	}
//};
