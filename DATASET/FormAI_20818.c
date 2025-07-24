//FormAI DATASET v1.0 Category: Physics simulation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_TIME 10.0       /* Maximum simulation time */
#define DT 0.01             /* Time increment */
#define K 10.0              /* Spring constant */
#define M 1.0               /* Mass of block */

struct state {
    double displacement;   /* Displacement of block */
    double velocity;       /* Velocity of block */
};

void update(struct state *s, double t, double dt)
{
    double force = -K * s->displacement;
    
    s->velocity += force/M * dt;
    s->displacement += s->velocity * dt;
}

int main()
{
    struct state s = { 0.1, 0.0 };   /* Initial state of system */
    double t;

    for (t = 0.0; t < MAX_TIME; t += DT) {
        printf("%f %f\n", t, s.displacement);  /* Print time and displacement */
        update(&s, t, DT);
    }

    return 0;
}