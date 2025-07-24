//FormAI DATASET v1.0 Category: Physics simulation ; Style: safe
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define PI 3.14159265359
#define GRAVITY 9.81

typedef struct {
    double x, y;
} Vector2D;

typedef struct {
    Vector2D r;       // position vector
    Vector2D v;       // velocity vector
    Vector2D a;       // acceleration vector
    double mass;      // mass of object
    double radius;    // radius of object
    double theta;     // angle of velocity vector with horizontal
} Object;

Object createObject(double x, double y, double vx, double vy, double mass, double radius) {
    Object object;
    object.r.x = x;
    object.r.y = y;
    object.v.x = vx;
    object.v.y = vy;
    object.mass = mass;
    object.radius = radius;
    object.theta = atan2(vy, vx);
    return object;
}

void updatePosition(Object *object, double dt) {
    object->r.x = object->r.x + object->v.x * dt;
    object->r.y = object->r.y + object->v.y * dt;
}

void updateVelocity(Object *object, double dt) {
    object->v.x = object->v.x + object->a.x * dt;
    object->v.y = object->v.y + object->a.y * dt;
    object->theta = atan2(object->v.y, object->v.x);
}

void updateAcceleration(Object *object) {
    object->a.x = 0;
    object->a.y = - GRAVITY;
}

void updateObject(Object *object, double dt) {
    updateAcceleration(object);
    updateVelocity(object, dt);
    updatePosition(object, dt);
}

void checkWallCollision(Object *object, double xleft, double xright, double ybottom, double ytop) {
    if (object->r.y - object->radius < ybottom) {
        object->r.y = ybottom + object->radius;
        object->v.y = - object->v.y;
        object->theta = atan2(object->v.y, object->v.x);
    } else if (object->r.y + object->radius > ytop) {
        object->r.y = ytop - object->radius;
        object->v.y = - object->v.y;
        object->theta = atan2(object->v.y, object->v.x);
    }
    if (object->r.x - object->radius < xleft) {
        object->r.x = xleft + object->radius;
        object->v.x = - object->v.x;
        object->theta = atan2(object->v.y, object->v.x);
    } else if (object->r.x + object->radius > xright) {
        object->r.x = xright - object->radius;
        object->v.x = - object->v.x;
        object->theta = atan2(object->v.y, object->v.x);
    }
}

void checkObjectCollision(Object *obj1, Object *obj2) {
    double dx = obj1->r.x - obj2->r.x;
    double dy = obj1->r.y - obj2->r.y;
    double dist = sqrt(dx*dx + dy*dy);
    if (dist <= obj1->radius + obj2->radius) {
        // calculate unit normal and unit tangent vectors
        double nx = dx / dist;
        double ny = dy / dist;
        double tx = - ny;
        double ty = nx;
        
        // project velocities onto unit normal and unit tangent vectors
        double v1n = obj1->v.x * nx + obj1->v.y * ny;
        double v1t = obj1->v.x * tx + obj1->v.y * ty;
        double v2n = obj2->v.x * nx + obj2->v.y * ny;
        double v2t = obj2->v.x * tx + obj2->v.y * ty;
        
        // calculate new normal and tangent velocities
        double v1n_new = (v1n * (obj1->mass - obj2->mass) + 2 * obj2->mass * v2n) / (obj1->mass + obj2->mass);
        double v2n_new = (v2n * (obj2->mass - obj1->mass) + 2 * obj1->mass * v1n) / (obj1->mass + obj2->mass);
        
        // calculate new velocities
        obj1->v.x = v1n_new * nx + v1t * tx;
        obj1->v.y = v1n_new * ny + v1t * ty;
        obj2->v.x = v2n_new * nx + v2t * tx;
        obj2->v.y = v2n_new * ny + v2t * ty;
        
        // adjust positions to avoid overlap
        double overlap = obj1->radius + obj2->radius - dist;
        obj1->r.x = obj1->r.x - overlap * nx / 2;
        obj1->r.y = obj1->r.y - overlap * ny / 2;
        obj2->r.x = obj2->r.x + overlap * nx / 2;
        obj2->r.y = obj2->r.y + overlap * ny / 2;
        
        // adjust angles
        obj1->theta = atan2(obj1->v.y, obj1->v.x);
        obj2->theta = atan2(obj2->v.y, obj2->v.x);
    }
}

int main() {
    // simulation parameters
    double dt = 0.01;
    double totalTime = 10;
    double xleft = -5;
    double xright = 5;
    double ybottom = 0;
    double ytop = 10;
    
    // create objects
    Object obj1 = createObject(-2, 6, 3, 4, 1, 0.5);
    Object obj2 = createObject(2, 6, -2, 3, 2, 1);
    
    // simulate motion
    for (double t = 0; t <= totalTime; t += dt) {
        // update object states
        updateObject(&obj1, dt);
        updateObject(&obj2, dt);
        
        // check for collisions
        checkWallCollision(&obj1, xleft, xright, ybottom, ytop);
        checkWallCollision(&obj2, xleft, xright, ybottom, ytop);
        checkObjectCollision(&obj1, &obj2);
        
        // print states
        printf("%.2f, %.2f, %.2f, %.2f, %.2f, %.2f\n", t, obj1.r.x, obj1.r.y, obj2.r.x, obj2.r.y, obj1.theta * 180 / PI);
    }
    
    return 0;
}