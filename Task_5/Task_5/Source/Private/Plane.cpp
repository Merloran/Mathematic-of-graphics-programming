#include "../Public/Plane.h"
#include "../Public/Line.h"

Line Plane::Intersect(Plane& P)
{
	Vec3f V = N.Cross(P.N);
	float Divisior = V.LengthSquared();
	if (Divisior != 0.0f)
	{
		float D1 = -this->P.DotProduct(N);
		float D2 = -P.P.DotProduct(P.N);

		return Line(V, ((N.Cross(P.N) * D1) + (N.Cross(V) * D2)) / Divisior);
	}
	return Line::INVALID();
}

float Plane::GetAngle(Plane& P)
{
	return Vec3f::RadToDeg(Vec3f::GetAngle(N, P.N));
}
