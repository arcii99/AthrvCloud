//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: shocked
#include <stdio.h>
#include <math.h>

#define G 0.0000001

struct planet {
    double x, y;        // position
    double vx, vy;      // velocity
    double mass;        // mass
};

void updatePosition(struct planet *p, double dt)
{
    p->x += p->vx * dt;
    p->y += p->vy * dt;
}

void updateVelocity(struct planet *p1, struct planet *p2, double dt)
{
    double dx = p2->x - p1->x;
    double dy = p2->y - p1->y;
    double d = sqrt(dx*dx + dy*dy);

    double f = G * p1->mass * p2->mass / (d*d);

    double fx = f * dx / d;
    double fy = f * dy / d;

    p1->vx += fx / p1->mass * dt;
    p1->vy += fy / p1->mass * dt;

    p2->vx -= fx / p2->mass * dt;
    p2->vy -= fy / p2->mass * dt;
}

int main()
{
    struct planet p1 = {0, 0, 0, 2, 10};    // (x,y) = (0,0), (vx,vy) = (0,2), mass = 10
    struct planet p2 = {10, 0, 0, -2, 10};  // (x,y) = (10,0), (vx,vy) = (0,-2), mass = 10

    double dt = 0.001;
    double t;

    for (t = 0; t < 100; t += dt)
    {
        updateVelocity(&p1, &p2, dt);
        updatePosition(&p1, dt);
        updatePosition(&p2, dt);

        printf("%lf %lf\n", p1.x, p1.y);
        printf("%lf %lf\n", p2.x, p2.y);
    }

    return 0;
}