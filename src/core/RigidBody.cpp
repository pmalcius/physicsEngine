#include "../../include/core/RigidBody.h"

// Constructor
RigidBody::RigidBody(Vector3D position, float mass)
    : position(position), velocity(), acceleration(), mass(mass) {}

// Get the current position
Vector3D RigidBody::getPosition() const {
    return position;
}

// Get the current velocity
Vector3D RigidBody::getVelocity() const {
    return velocity;
}

// Get the mass of the object
float RigidBody::getMass() const {
    return mass;
}

void RigidBody::setPosition(const Vector3D& newPosition) {
    position = newPosition;
}

void RigidBody::setVelocity(const Vector3D& newVelocity) {
    velocity = newVelocity;
}