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
    Camera(const Vec3f&position, const Vec3f& direction, const Vec3f&up);
    Camera();

    void rotateY(float angle);
    void rotateX(float angle);
    void rotateZ(float angle);
    void rotateAxis(float angle, Vec3f axis);



};