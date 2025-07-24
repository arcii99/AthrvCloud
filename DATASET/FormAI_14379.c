//FormAI DATASET v1.0 Category: Physics simulation ; Style: protected
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main()
{
    float t, dt, a, v, x, f, m;
    float k, b, A, f0, w, T, phi, F;

    // Initializing the values
    m = 2; // mass of object
    k = 5; // spring constant
    b = 0.5; // damping coefficient
    A = 1; // amplitude
    f0 = 2; // frequency
    phi = 0; // phase difference
    T = (2 * 3.1416) / f0; // time period
    w = (2 * 3.1416) * f0; // angular velocity
    t = 0; // initial time
    x = 0.25; // initial displacement
    v = 0; f = -k * x;
    a = (f - b * v) / m;

    // Calculating and displaying Values
    printf("Calculating values for a damped forced oscillator:\n\n");
    printf("Time\t\tDisplacement\tVelocity\tAcceleration\n\n");
    printf("%.4f\t\t%.4f\t\t%.4f\t\t%.4f\n", t, x, v, a);

    for (int i = 1; i <= 50; i++) // simulating 50 oscillations
    {
        dt = 0.01;
        F = A * sin(w * t + phi);
        f = -k * x - b * v + F; // equation of motion
        a = f / m;
        v = v + a * dt;
        x = x + v * dt;
        t = t + dt;
        printf("%.4f\t\t%.4f\t\t%.4f\t\t%.4f\n", t, x, v, a);
      }
    return 0;
}