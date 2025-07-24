//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: complex
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
// define simulation parameters
#define TIME_STEP 0.001
#define TIME_LIMIT 10.0
#define GRAVITY_CONSTANT 6.674E-11


typedef struct
{
    double x, y,z, vx, vy, vz, m;
} Body;

typedef struct
{
    double x, y, z;
} Vector;


Vector vector_subtract(Vector v1, Vector v2)
{
    Vector v;
    v.x = v1.x - v2.x;
    v.y = v1.y - v2.y;
    v.z = v1.z - v2.z;
    return v;
}


Vector vector_add(Vector v1, Vector v2)
{
    Vector v;
    v.x = v1.x + v2.x;
    v.y = v1.y + v2.y;
    v.z = v1.z + v2.z;
    return v;
}


double vector_dot(Vector v1, Vector v2)
{
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}


Vector vector_scale(Vector v, double scale)
{
    Vector result;
    result.x = v.x * scale;
    result.y = v.y * scale;
    result.z = v.z * scale;
    return result;
}



Vector vector_cross(Vector v1, Vector v2)
{
    Vector result;
    result.x = v1.y * v2.z - v1.z * v2.y;
    result.y = v1.z * v2.x - v1.x * v2.z;
    result.z = v1.x * v2.y - v1.y * v2.x;
    return result;
}


Vector vector_normalise(Vector v)
{
    double magnitude = sqrt(vector_dot(v, v));
    return vector_scale(v, 1.0 / magnitude);
}


Vector gravitational_force(Body b1, Body b2)
{
    Vector dir = vector_subtract((Vector) { b2.x, b2.y, b2.z}, (Vector) { b1.x, b1.y, b1.z });
    double dist = sqrt(vector_dot(dir, dir));
    double force = GRAVITY_CONSTANT * b1.m * b2.m / (dist * dist);
    return vector_scale(dir, force / dist);
}


void update_positions(Body *bodies, int num_bodies, double dt)
{
    for (int i = 0; i < num_bodies; i++)
    {
        bodies[i].x += bodies[i].vx * dt;
        bodies[i].y += bodies[i].vy * dt;
        bodies[i].z += bodies[i].vz * dt;
    }
}


void update_velocities(Body *bodies, int num_bodies, double dt)
{
    for (int i = 0; i < num_bodies; i++)
    {
        Vector force = { 0.0, 0.0, 0.0 };
        for (int j = 0; j < num_bodies; j++)
        {
            if (i == j) {
                continue;
            }
            force = vector_add(force, gravitational_force(bodies[i], bodies[j]));
        }
        bodies[i].vx += force.x / bodies[i].m * dt;
        bodies[i].vy += force.y / bodies[i].m * dt;
        bodies[i].vz += force.z / bodies[i].m * dt;
    }
}


void print_bodies(Body *bodies, int num_bodies)
{
    for (int i = 0; i < num_bodies; i++)
    {
        printf("Body %d: x = %f, y = %f, z = %f, vx = %f, vy = %f, vz = %f, m = %f\n",
                i + 1, bodies[i].x, bodies[i].y, bodies[i].z,
                bodies[i].vx, bodies[i].vy, bodies[i].vz, bodies[i].m);
    }
}


void simulate(Body *bodies, int num_bodies, double time_step, double time_limit)
{
    for (double t = 0; t < time_limit; t += time_step)
    {
        update_positions(bodies, num_bodies, time_step);
        update_velocities(bodies, num_bodies, time_step);
    }
}



int main(int argc, char **argv)
{
    Body bodies[9] = {
        { -2.720895548935150E-03, -4.481817062184051E-03, 1.689124047676548E-05,  2.280792467889578E-06 * 365.25, -1.622879421276724E-06 * 365.25, -8.799931919744947E-08 * 365.25, 3.114e23 }, // Mercury
        { -9.778786032548407E-02, -3.531610515421820E-01, -2.040115290074468E-02,  3.929207603841537E-03 * 365.25, -1.164894612819899E-03 * 365.25, -1.880032576834052E-04 * 365.25, 4.880e24 }, // Venus
        { -8.937866360422202E-01,  4.356185907173215E-01,  4.555934323226894E-02, -1.538298921783713E-03 * 365.25, -2.926384087684442E-03 * 365.25,  2.225946953296627E-05 * 365.25, 5.976e24 }, // Earth
        { -5.417505734336838E-01, -8.924005947741783E-01,  9.513102524511898E-03,  1.656328443906977E-03 * 365.25, -1.014853408031964E-03 * 365.25, -3.234872077093211E-05 * 365.25, 6.586e23 }, // Mars
        {  4.780184458549181E-01, -9.737626238780030E+00,  2.157513212736875E-02,  7.477211671259900E-04 * 365.25,  4.514539077813319E-03 * 365.25, -1.005785550125488E-04 * 365.25, 1.899e27 }, // Jupiter
        {  1.305902556369327E+01, -1.194410794853025E+01, -1.950891497478618E-01,  2.809706891793174E-03 * 365.25,  3.012499132581664E-03 * 365.25, -1.087146419965094E-04 * 365.25, 5.685e26 }, // Saturn
        {  2.317555755344551E+01, -1.069659673049317E+01, -4.114470474434063E-01,  1.885218368367769E-03 * 365.25,  3.936664414835791E-03 * 365.25, -4.517797189993315E-05 * 365.25, 8.682e25 }, // Uranus
        {  2.436590596640697E+01,  1.168935802486205E+01, -1.442062442576083E-01, -1.463660123758163E-03 * 365.25,  2.953044867637237E-03 * 365.25,  8.676747153479219E-05 * 365.25, 1.024e26 }, // Neptune
        {  1.071069393297432E+01,  1.116136647961031E+01, -1.614954047577246E-01, -2.635260036990786E-03 * 365.25,  2.615077562622051E-03 * 365.25,  9.607114453563756E-04 * 365.25, 1.471e22 }  // Pluto
    };

    int num_bodies = sizeof(bodies) / sizeof(Body);

    // simulate the system
    simulate(bodies, num_bodies, TIME_STEP, TIME_LIMIT);

    // print out final positions and velocities
    print_bodies(bodies, num_bodies);

    return 0;
}