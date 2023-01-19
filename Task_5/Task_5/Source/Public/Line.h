#pragma once
#include "Vector3.h"
class Plane;

class Line
{
public:
	Vec3f Direction;
	Vec3f Point;

	Line();
	Line(Vec3f Direction, Vec3f Point);
	
	Vec3f Intersect(Line& L);
	
	Vec3f Intersect(Plane& P);
	
	float GetAngle(Line& L);
	
	float GetAngle(Plane& Point);
	
	static Line INVALID();
};

