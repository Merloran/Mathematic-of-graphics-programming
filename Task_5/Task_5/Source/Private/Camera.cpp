

#include "../Public/Camera.h"
#include "../Public/Quaternion.h"

Camera::Camera(const Vec3f& position, const Vec3f& direction, const Vec3f& up) 
    : position(position)
    , direction(direction)
    , up(up) 
{
    this->radius = sqrt(position.X * position.X + position.Y * position.Y + position.Z * position.Z);
}

Camera::Camera(float radius) : radius(radius) 
{
    this->position = Vec3f(0, 0, radius);
    this->direction = Vec3f(0, 0, -1);
    this->up = Vec3f(0, 1, 0);
}

void Camera::rotateX(float angle) 
{
    position = Quatf::Rotate(position, angle, Vec3f(1, 0, 0));
    direction = Quatf::Rotate(direction, angle, Vec3f(1, 0, 0));
    direction = direction.Normalize();
    up = Quatf::Rotate(up, angle, Vec3f(1, 0, 0));
    up = up.Normalize();
}

void Camera::rotateY(float angle) {
    position = Quatf::Rotate(position, angle, Vec3f(0, 1, 0));
    direction = Quatf::Rotate(direction, angle, Vec3f(0, 1, 0));
    direction = direction.Normalize();
    up = Quatf::Rotate(up, angle, Vec3f(0, 1, 0));
    up = up.Normalize();
}

void Camera::rotateZ(float angle)
{
    position = Quatf::Rotate(position, angle, Vec3f(0, 0, 1));
    direction = Quatf::Rotate(direction, angle, Vec3f(0, 0, 1));
    direction = direction.Normalize();
    up = Quatf::Rotate(up, angle, Vec3f(0, 0, 1));
    up = up.Normalize();
}

void Camera::rotateAxis(float angle, Vec3f axis) 
{
    position = Quatf::Rotate(position, angle, axis);
    direction = Quatf::Rotate(direction, angle, axis);
    direction = direction.Normalize();
    up = Quatf::Rotate(up, angle, axis);
    up = up.Normalize();
}