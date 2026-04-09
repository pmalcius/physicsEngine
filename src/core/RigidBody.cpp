#include "../../include/core/RigidBody.h"

// Constructor
RigidBody::RigidBody(Vector3D position, float mass)
    : position(position), velocity(), acceleration(), mass(mass) {}

// Apply a force to the object
void RigidBody::applyForce(const Vector3D& force) {
    // TODO: Implement force application logic (e.g., F = ma -> a = F / m)
}

// Update the object's position and velocity
void RigidBody::update(float deltaTime) {
    // TODO: Implement update logic (e.g., position += velocity * deltaTime)
}

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