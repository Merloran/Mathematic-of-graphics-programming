#include "../Public/Plane.h"
#include "../Public/Line.h"

Line Plane::Intersect(Plane& P)
{
	Vec3f Direction = Normal.Cross(P.Normal);
	float Divisior = Direction.LengthSquared();
	if (Divisior != 0.0f)
	{
		float D1 = -this->Point.DotProduct(Normal);
		float D2 = -P.Point.DotProduct(P.Normal);

		return Line(Direction, ((Normal.Cross(P.Normal) * D1) + (Normal.Cross(Direction) * D2)) / Divisior);
	}
	return Line::INVALID();
}

float Plane::GetAngle(Plane& P)
{
	return Vec3f::RadToDeg(Vec3f::GetAngle(Normal, P.Normal));
}
