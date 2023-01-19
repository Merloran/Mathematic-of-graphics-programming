#pragma once
#include "Vector3.h"
class Line;

class Plane
{
public:
	Vec3f N; //Normal to plane
	Vec3f P; //Point on plane
	
	Plane(Vec3f N, Vec3f P)
		: N(N)
		, P(P)
	{}
	
	
	Line Intersect(Plane& P);
	
	float GetAngle(Plane& P);
};

