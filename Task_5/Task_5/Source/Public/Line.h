#pragma once
#include "Vector3.h"
class Plane;

class Line
{
public:
	Vec3f V;
	Vec3f P;

	Line();
	Line(Vec3f V, Vec3f P);
	
	Vec3f Intersect(Line& L);
	
	Vec3f Intersect(Plane& P);
	
	float GetAngle(Line& L);
	
	float GetAngle(Plane& P);
	
	static Line INVALID();
};

