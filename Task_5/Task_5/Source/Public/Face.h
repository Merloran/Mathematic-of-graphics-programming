#pragma once
#include "Plane.h"
#include "Line.h"

class Face : public Plane
{
public:
	Line Egdes[4];

	bool Intersect(Line& L);
};

