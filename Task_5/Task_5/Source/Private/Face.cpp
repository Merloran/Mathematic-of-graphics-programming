#include "../Public/Face.h"

bool Face::Intersect(Line& L)
{
	if (L.V.DotProduct(N) == 0.0)
	{
		return false;
	}
	Vec3f Points[4];
	Points[0] = Egdes[0].Intersect(Egdes[1]);
	Points[1] = Egdes[0].Intersect(Egdes[2]);
	Points[2] = Egdes[3].Intersect(Egdes[1]);
	Points[3] = Egdes[3].Intersect(Egdes[2]);

	Vec3f normal = (Points[1] - Points[0]).Cross(Points[3] - Points[0]).Normalize();
	float d = normal.DotProduct(Points[0] - L.P);
	float t = d / normal.DotProduct(L.V);
	if (t < 0)
	{
		return false;
	}
	Vec3f intersectionPoint = L.P + L.V * t;

	Vec3f v1 = (Points[1] - Points[0]).Cross(intersectionPoint - Points[0]);
	Vec3f v2 = (Points[3] - Points[1]).Cross(intersectionPoint - Points[1]);
	Vec3f v3 = (Points[0] - Points[3]).Cross(intersectionPoint - Points[4]);
	Vec3f v4 = (Points[2] - Points[0]).Cross(intersectionPoint - Points[0]);

	//if (Vector3.Dot(v1, v2) > 0 && Vector3.Dot(v2, v3) > 0 && Vector3.Dot(v3, v4) > 0)
	//	return true;
	//else
	//	return false;

	//Vec3f Point = L.P + L.V * T;


	return true;
}
