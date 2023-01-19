#pragma once
#include "Vector3.h"
class Line;

class Plane
{
public:
	Vec3f Normal; //Normal to plane
	Vec3f Point; //Point on plane
	
	Plane(Vec3f Normal, Vec3f Point)
		: Normal(Normal)
		, Point(Point)
	{}
	
	
	Line Intersect(Plane& P);
	
	float GetAngle(Plane& P);
};

