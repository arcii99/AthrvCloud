//FormAI DATASET v1.0 Category: Physics simulation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265359

int main()
{
    // initialize variables
    double mass = 0.5; // kg
    double radius = 0.1; // m
    double Cd = 0.47; // drag coefficient of a sphere
    double rho = 1.2; // kg/m^3 (density of air)
    double A = PI * pow(radius, 2); // m^2 (cross-sectional area of sphere)
    double omega = 0; // angular velocity (rad/s)
    double alpha = 0; // angular acceleration (rad/s^2)
    double t = 0; // time (s)
    double dt = 0.01; // time step (s)
    double T = 10; // total simulation time (s)
    double theta = PI / 4; // initial angle (rad)
    double v0 = 10; // initial velocity (m/s)
    double vx = v0 * cos(theta); // horizontal velocity (m/s)
    double vy = v0 * sin(theta); // vertical velocity (m/s)
    double x = 0; // horizontal position (m)
    double y = 0; // vertical position (m)
    double ax = 0; // horizontal acceleration (m/s^2)
    double ay = -9.81; // vertical acceleration (m/s^2)
    double Fd = 0; // drag force (N)
    double Fnet = 0; // net force (N)
    double torque = 0; // torque (Nm)

    // simulate projectile motion with air resistance and spin
    while (t < T) {
        // calculate net force in x and y directions
        Fd = 0.5 * Cd * rho * A * pow(vx, 2);
        Fnet = mass * ay - Fd;
        ax = Fnet / mass;
        Fnet = mass * ax;
        ay = -9.81 + (0.5 * Cd * rho * A * pow(vy, 2) / mass);
        ay = Fnet / mass;

        // calculate torque
        if (y <= radius) { // sphere is in contact with the ground
            alpha = -0.01 * omega; // frictional torque
            if (omega < 0.1) {
                omega = 0;
            }
        } else { // sphere is in free flight
            alpha = 0.1 * vy; // Magnus torque
        }
        torque = alpha * (2.0 / 5.0 * mass * radius * radius); // moment of inertia of sphere

        // update angular velocity and position
        omega += alpha * dt;
        theta += omega * dt;

        // update velocity and position
        vx += ax * dt;
        vy += ay * dt;
        x += vx * dt;
        y += vy * dt;

        // print position and velocity
        printf("t=%lf, x=%lf, y=%lf, vx=%lf, vy=%lf, omega=%lf\n", t, x, y, vx, vy, omega);

        // update time
        t += dt;
    }

    return 0;
}