#include "../../include/core/PhysicsEngine.h"

void PhysicsEngine::applyForce(RigidBody& body, const Vector3D& force, float deltaTime) {
    Vector3D acceleration = force / body.getMass();
    body.setVelocity(body.getVelocity() + acceleration * deltaTime);
}

void PhysicsEngine::update(RigidBody& body, float deltaTime) {
    body.setPosition(body.getPosition() + body.getVelocity() * deltaTime);
}