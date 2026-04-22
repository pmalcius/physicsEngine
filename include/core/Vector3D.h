#ifndef VECTOR3D_H
#define VECTOR3D_H

class Vector3D {
public:
    float x, y, z;

    // Constructors
    Vector3D();
    Vector3D(float x, float y, float z);

    // Vector operations
    Vector3D add(const Vector3D& other) const;
    Vector3D sub(const Vector3D& other) const;
    Vector3D mult(float scalar) const;
    Vector3D div(float scalar) const;

    float dot(const Vector3D& other) const;
    Vector3D cross(const Vector3D& other) const;

    float magnitude() const;
    Vector3D normalize() const;

    // Operator overloads (delegate to named methods above)
    Vector3D operator+(const Vector3D& other) const;
    Vector3D operator-(const Vector3D& other) const;
    Vector3D operator*(float scalar) const;
    Vector3D operator/(float scalar) const;
    bool operator==(const Vector3D& other) const;
};

#endif