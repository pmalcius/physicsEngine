#ifndef VECTOR3D_H
#define VECTOR3D_H

class Vector3D {
public:
    float x, y, z;

    // Constructors
    Vector3D();
    Vector3D(float x, float y, float z);

    // Vector operations
    Vector3D add(const Vector3D& a, const Vector3D& b);
    Vector3D sub(const Vector3D& a, const Vector3D& b);
    Vector3D mult(const Vector3D& a, float scalar);
    Vector3D div(const Vector3D& a, float scalar);

    Vector3D dot(const Vector3D& a, const Vector3D& b);
    Vector3D cross(const Vector3D& a, const Vector3D& b);

    Vector3D magnitude(const Vector3D& a);
    Vector3D normalize(const Vector3D& a);
};

#endif