//#pragma once
//#include "Vector3.h"
//#include "PlaneExp.h"
//
//template <typename Type>
//class Line
//{
//public:
//	Vector3<Type> V;
//	Vector3<Type> P;
//
//	Line(Vector3<Type> V, Vector3<Type> P)
//	: V(V)
//	, P(P)
//	{}
//
//	Vector3<Type> Intersect(Line<Type>& L)
//	{
//
//		if (V.Cross(L.V).LengthSquared() != 0.0f)
//		{
//			Type T = (P - L.P).Cross(V).DotProduct(V.Cross(L.V)) / V.Cross(L.V).LengthSquared();
//			return P + V * T;
//		}
//		return Vector3<Type>::INVALID();
//	}
//
//	Vector3<Type> Intersect(class Plane<Type>& P)
//	{
//		if (V.DotProduct(P.N) != 0.0)
//		{
//			Type T = -P.N.DotProduct(this->P - P.P) / P.N.DotProduct(V);
//			return { this->P + V * T };
//		}
//		return Vector3<Type>::INVALID();
//	}
//
//	Type GetAngle(Line<Type>& L)
//	{
//		return Vector3<Type>::RadToDeg(Vector3<Type>::GetAngle(V, L.V));
//	}
//
//	Type GetAngle(class Plane<Type>& P)
//	{
//		return Vector3<Type>::RadToDeg(Vector3<Type>::GetAngle(V, P.N));
//	}
//
//	static Line<Type> INVALID()
//	{
//		return Line<Type>(Vector3<Type>::INVALID(), Vector3<Type>::INVALID());
//	}
//};