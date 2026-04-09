#ifndef RIGIDBODY_H
#define RIGIDBODY_H

#include "Vector3D.h"

// RigidBody is an object that has properties such as mass, velocity, and position
// It can apply forces to change its acceleration
// It updates its position and velocity every frame
class RigidBody {
public:
    // Constructor
    RigidBody(Vector3D position, float mass);

    // Methods
    void applyForce(const Vector3D& force); // Apply a force to the object
    void update(float deltaTime);          // Update position and velocity

    // Getters (optional, for accessing private variables)
    Vector3D getPosition() const;
    Vector3D getVelocity() const;
    float getMass() const;

private:
    // Properties
    Vector3D position;     // Current position in 3D space
    Vector3D velocity;     // Current velocity
    Vector3D acceleration; // Current acceleration
    float mass;            // Mass of the object
};

#endif