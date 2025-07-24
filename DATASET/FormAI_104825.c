//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: genious
#include <stdio.h>
#include <math.h>

/* Define our circuit parameters */
#define R1 100.0
#define R2 200.0
#define C1 1e-6
#define C2 0.5e-6

/* Define the simulation parameters */
#define T_STEP 1e-4
#define T_STOP 1.0

/* Compute the capacitive reactance of the capacitors */
#define X_C1 (1.0 / (2.0 * M_PI * C1))
#define X_C2 (1.0 / (2.0 * M_PI * C2))

/* Define the function to compute the voltage across C2 */
double compute_voltage_c2(double t, double v_in) {
    static double v_c1 = 0, v_c2_last = 0;
    double v_c2;

    /* Compute the new voltage across C1 */
    v_c1 += (v_in - v_c1) / (R1 * C1) * T_STEP;

    /* Compute the new voltage across C2 */
    v_c2 = (v_c1 - v_c2_last) / (R2 * C2 * X_C2 * X_C2 + 1) * X_C2;
    v_c2_last = v_c2;

    return v_c2;
}

int main(void) {
    double t, v_in, v_c2;

    for (t = 0; t <= T_STOP; t += T_STEP) {
        /* Step input voltage */
        v_in = t <= T_STOP / 3.0 ? 1.0 : 0.0;

        /* Compute the voltage across C2 */
        v_c2 = compute_voltage_c2(t, v_in);

        /* Output the results */
        printf("%.6f,%.6f,%.6f\n", t, v_in, v_c2);
    }

    return 0;
}