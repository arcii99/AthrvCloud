//FormAI DATASET v1.0 Category: Physics simulation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Vector3D {
    float x;
    float y;
    float z;
} Vector3D;

typedef struct Particle {
    Vector3D position;
    Vector3D velocity;
    float mass;
} Particle;

float computeDistance(Vector3D a, Vector3D b) {
    float distance = sqrt(pow((b.x-a.x), 2) + pow((b.y-a.y), 2) + pow((b.z-a.z), 2));
    return distance;
}

Vector3D computeGravityForce(Particle a, Particle b) {
    float distance = computeDistance(a.position, b.position);
    float forceMagnitude = (a.mass*b.mass) / pow(distance, 2);
    Vector3D direction;
    direction.x = (b.position.x - a.position.x) / distance;
    direction.y = (b.position.y - a.position.y) / distance;
    direction.z = (b.position.z - a.position.z) / distance;
    Vector3D force;
    force.x = direction.x * forceMagnitude;
    force.y = direction.y * forceMagnitude;
    force.z = direction.z * forceMagnitude;
    return force;
}

void updateParticlePosition(Particle *p, float deltaTime) {
    Vector3D acceleration;
    acceleration.x = 0;
    acceleration.y = -9.8;
    acceleration.z = 0;
    Vector3D deltaVelocity;
    deltaVelocity.x = acceleration.x * deltaTime;
    deltaVelocity.y = acceleration.y * deltaTime;
    deltaVelocity.z = acceleration.z * deltaTime;
    p->velocity.x += deltaVelocity.x;
    p->velocity.y += deltaVelocity.y;
    p->velocity.z += deltaVelocity.z;
    Vector3D deltaPosition;
    deltaPosition.x = p->velocity.x * deltaTime;
    deltaPosition.y = p->velocity.y * deltaTime;
    deltaPosition.z = p->velocity.z * deltaTime;
    p->position.x += deltaPosition.x;
    p->position.y += deltaPosition.y;
    p->position.z += deltaPosition.z;
}

int main() {
    Particle particle1;
    particle1.position.x = 0;
    particle1.position.y = 0;
    particle1.position.z = 0;
    particle1.velocity.x = 10;
    particle1.velocity.y = 10;
    particle1.velocity.z = 0;
    particle1.mass = 10;

    Particle particle2;
    particle2.position.x = 0;
    particle2.position.y = 5;
    particle2.position.z = 0;
    particle2.velocity.x = -10;
    particle2.velocity.y = 10;
    particle2.velocity.z = 0;
    particle2.mass = 20;

    float deltaTime = 0.01;
    float time = 0;
    while (time < 10) {
        Vector3D gravityForce = computeGravityForce(particle1, particle2);
        Vector3D gravityForce2;
        gravityForce2.x = -gravityForce.x;
        gravityForce2.y = -gravityForce.y;
        gravityForce2.z = -gravityForce.z;
        Vector3D deltaVelocity1;
        deltaVelocity1.x = gravityForce.x / particle1.mass * deltaTime;
        deltaVelocity1.y = gravityForce.y / particle1.mass * deltaTime;
        deltaVelocity1.z = gravityForce.z / particle1.mass * deltaTime;
        Vector3D deltaVelocity2;
        deltaVelocity2.x = gravityForce2.x / particle2.mass * deltaTime;
        deltaVelocity2.y = gravityForce2.y / particle2.mass * deltaTime;
        deltaVelocity2.z = gravityForce2.z / particle2.mass * deltaTime;
        particle1.velocity.x += deltaVelocity1.x;
        particle1.velocity.y += deltaVelocity1.y;
        particle1.velocity.z += deltaVelocity1.z;
        particle2.velocity.x += deltaVelocity2.x;
        particle2.velocity.y += deltaVelocity2.y;
        particle2.velocity.z += deltaVelocity2.z;

        updateParticlePosition(&particle1, deltaTime);
        updateParticlePosition(&particle2, deltaTime);

        printf("t = %.2f, p1: (%.2f, %.2f, %.2f), p2: (%.2f, %.2f, %.2f)\n", time, particle1.position.x, particle1.position.y, particle1.position.z, particle2.position.x, particle2.position.y, particle2.position.z);

        time += deltaTime;
    }

    return 0;
}