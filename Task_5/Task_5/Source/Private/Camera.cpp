

#include "../Public/Camera.h"
#include "../Public/Quaternion.h"

Camera::Camera(Vec3f& position, const Vec3f& direction, const Vec3f& up) 
    : position(position)
    , direction(direction)
    , up(up) 
    , radius(position.Length())
{}

Camera::Camera(float radius) 
    : radius(radius) 
{
    this->position = Vec3f(0, 0, radius);
    this->direction = Vec3f(0, 0, -1);
    this->up = Vec3f(0, 1, 0);
}

void Camera::RotateX(float angle) 
{
    position = Quatf::Rotate(position, angle, Vec3f(1, 0, 0));
    direction = Quatf::Rotate(direction, angle, Vec3f(1, 0, 0));
    direction = direction.Normalize();
    up = Quatf::Rotate(up, angle, Vec3f(1, 0, 0));
    up = up.Normalize();
}

void Camera::RotateY(float angle) {
    position = Quatf::Rotate(position, angle, Vec3f(0, 1, 0));
    direction = Quatf::Rotate(direction, angle, Vec3f(0, 1, 0));
    direction = direction.Normalize();
    up = Quatf::Rotate(up, angle, Vec3f(0, 1, 0));
    up = up.Normalize();
}

void Camera::RotateZ(float angle)
{
    position = Quatf::Rotate(position, angle, Vec3f(0, 0, 1));
    direction = Quatf::Rotate(direction, angle, Vec3f(0, 0, 1));
    direction = direction.Normalize();
    up = Quatf::Rotate(up, angle, Vec3f(0, 0, 1));
    up = up.Normalize();
}

void Camera::RotateAxis(float angle, Vec3f axis) 
{
    position = Quatf::Rotate(position, angle, axis);
    direction = Quatf::Rotate(direction, angle, axis);
    direction = direction.Normalize();
    up = Quatf::Rotate(up, angle, axis);
    up = up.Normalize();
}