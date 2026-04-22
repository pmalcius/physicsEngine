#ifndef PHYSICSENGINE_H
#define PHYSICSENGINE_H

#include "RigidBody.h"

class PhysicsEngine {
public:
    static void applyForce(RigidBody& body, const Vector3D& force, float deltaTime);

    static void update(RigidBody& body, float deltaTime);
};

#endif