#include "../Public/Line.h"
#include "../Public/Plane.h"

Line::Line()
	: V(Vec3f())
	, P(Vec3f())
{
}

Line::Line(Vec3f V, Vec3f P)
	: V(V)
	, P(P)
{
}

Vec3f Line::Intersect(Line& L)
{

	if (V.Cross(L.V).LengthSquared() != 0.0f)
	{
		float T = (P - L.P).Cross(V).DotProduct(V.Cross(L.V)) / V.Cross(L.V).LengthSquared();
		return P + V * T;
	}
	return Vec3f::INVALID();
}

Vec3f Line::Intersect(Plane& P)
{
	if (V.DotProduct(P.N) != 0.0)
	{
		float T = -P.N.DotProduct(this->P - P.P) / P.N.DotProduct(V);
		return this->P + V * T;
	}
	return Vec3f::INVALID();
}

float Line::GetAngle(Line& L)
{
	return Vec3f::RadToDeg(Vec3f::GetAngle(V, L.V));
}

float Line::GetAngle(Plane& P)
{
	return Vec3f::RadToDeg(Vec3f::GetAngle(V, P.N));
}

Line Line::INVALID()
{
	return Line(Vec3f::INVALID(), Vec3f::INVALID());
}
