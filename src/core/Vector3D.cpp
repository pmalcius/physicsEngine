#include "../../include/core/Vector3D.h"
#include <cmath>

// Constructors
Vector3D::Vector3D() : x(0), y(0), z(0) {}

Vector3D::Vector3D(float x, float y, float z) : x(x), y(y), z(z) {}

// Vector operations
Vector3D Vector3D::add(const Vector3D& other) const {
    return Vector3D(x + other.x, y + other.y, z + other.z);
}

Vector3D Vector3D::sub(const Vector3D& other) const {
    return Vector3D(x - other.x, y - other.y, z - other.z);
}

Vector3D Vector3D::mult(float scalar) const{
    return Vector3D(scalar * x, scalar * y, scalar * z);
}

Vector3D Vector3D::div(float scalar) const {
    if (scalar == 0){
        return Vector3D(0, 0, 0);
    }
    return Vector3D(x / scalar, y/ scalar, z / scalar);
}

// Dot product
float Vector3D::dot(const Vector3D& other) const {
    return ((x * other.x) + (y * other.y) + (z * other.z));
}

// Cross product
Vector3D Vector3D::cross(const Vector3D& other) const  {
    return Vector3D(((y*other.z)-(z*other.y)), ((x*other.z) - (z*other.x)), ((x*other.y) - (y*other.x)));
}

// Magnitude
float Vector3D::magnitude() const {
    return sqrt((x*x) + (y*y) + (z*z));
}

// Normalize
Vector3D Vector3D::normalize() const {
    float mag = magnitude();
    if (mag == 0) {
        return Vector3D(0, 0, 0);
    }
    return Vector3D(x/mag, y/mag, z/mag);
}