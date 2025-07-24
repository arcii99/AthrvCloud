//FormAI DATASET v1.0 Category: Physics simulation ; Style: excited
#include <stdio.h>
#include <math.h>

// Define constants
#define G 9.81      // Acceleration due to gravity
#define RHO 1.2     // Air density
#define C_D 0.47    // Drag coefficient
#define A 0.05      // Cross-sectional area
#define M 1.0       // Mass of ball
#define MU 0.3      // Coefficient of friction
#define DT 1e-3     // Time step
#define T_MAX 10.0  // Maximum simulation time

int main() {
    // Declare variables
    double x = 0.0;     // Position
    double v = 0.0;     // Velocity
    double a = 0.0;     // Acceleration
    double v_x = 0.0;   // Horizontal velocity
    double v_y = 0.0;   // Vertical velocity
    double f_g = 0.0;   // Force of gravity
    double f_d = 0.0;   // Force of air resistance
    double f_f = 0.0;   // Force of friction
    double t = 0.0;     // Time

    // Set initial conditions
    x = 0.0;
    v = 0.0;
    v_x = 10.0;
    v_y = 0.0;

    // Simulate motion
    while (t <= T_MAX) {
        // Calculate forces
        f_g = -M * G;
        f_d = -0.5 * RHO * C_D * A * v * v;
        f_f = -MU * M * G;

        // Calculate acceleration
        a = (f_g + f_d + f_f) / M;

        // Update velocity
        v_x = v_x + a * DT;
        v_y = v_y + G * DT;

        // Update position
        x = x + v_x * DT;
        if (x < 0) {
            x = 0;
            v_x = -v_x * 0.9;
        }

        // Update time
        t = t + DT;

        // Print results
        printf("%.3f, %.3f\n", t, x);
    }

    return 0;
}