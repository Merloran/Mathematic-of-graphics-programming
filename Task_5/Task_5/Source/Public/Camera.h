#pragma once
#include "Line.h"

class Camera {
public:
    Vec3f position;
    float radius;
    Vec3f direction;
    Vec3f up;

    Camera(float radius);

    Line ray = Line(position, direction);
    Camera(Vec3f& position, const Vec3f& direction, const Vec3f&up);
    Camera();

    void RotateY(float angle);
    void RotateX(float angle);
    void RotateZ(float angle);
    void RotateAxis(float angle, Vec3f axis);



};