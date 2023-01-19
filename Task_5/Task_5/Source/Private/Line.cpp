#include "../Public/Line.h"
#include "../Public/Plane.h"

Line::Line()
	: Direction(Vec3f())
	, Point(Vec3f())
{
}

Line::Line(Vec3f Direction, Vec3f Point)
	: Direction(Direction)
	, Point(Point)
{
}

Vec3f Line::Intersect(Line& L)
{

	if (Direction.Cross(L.Direction).LengthSquared() != 0.0f)
	{
		float T = (Point - L.Point).Cross(Direction).DotProduct(Direction.Cross(L.Direction)) / Direction.Cross(L.Direction).LengthSquared();
		return Point + Direction * T;
	}
	return Vec3f::INVALID();
}

Vec3f Line::Intersect(Plane& P)
{
	if (Direction.DotProduct(P.Normal) != 0.0f)
	{
		float T = -P.Normal.DotProduct(Point - P.Point) / P.Normal.DotProduct(Direction);
		return Point + (Direction * T);
	}
	return Vec3f::INVALID();
}

float Line::GetAngle(Line& L)
{
	return Vec3f::RadToDeg(Vec3f::GetAngle(Direction, L.Direction));
}

float Line::GetAngle(Plane& Point)
{
	return Vec3f::RadToDeg(Vec3f::GetAngle(Direction, Point.Normal));
}

Line Line::INVALID()
{
	return Line(Vec3f::INVALID(), Vec3f::INVALID());
}
