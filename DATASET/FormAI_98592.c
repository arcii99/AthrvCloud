//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: brave
#include<stdio.h>
#include<math.h>

#define MAX_ITER 10000
#define H 0.1

// Function to calculate the derivative of the circuit at a given state
void der_func(double state[], double der[]) {

    double v1 = state[0];
    double v2 = state[1];
    double iL = state[2];

    double R1 = 10.0;
    double R2 = 140.0;
    double R3 = 1100.0;
    double C = 1e-6;
    double L = 220e-3;

    double iC = C * (v1 - v2) / H;
    double vL = L * iL / H;

    double eq1 = iC + (v2 - v1) / R1;
    double eq2 = (v1 - v2) / R1 + iL / R2;
    double eq3 = (v1 - v2) / R2 + iL / R3;

    der[0] = eq1;
    der[1] = eq2;
    der[2] = eq3;
}

// Function to simulate the circuit
void simulate(double init_val[]) {
    double t = 0;
    double state[3];
    for(int i=0; i<3; i++) state[i] = init_val[i];

    printf("Time (s)\tv1 (V)\tv2 (V)\tiL (A)\n");

    for (int i = 0; i < MAX_ITER; i++) {
        printf("%lf\t%lf\t%lf\t%lf\n", t, state[0], state[1], state[2]);
        double k1[3], k2[3], k3[3], k4[3], temp[3];

        der_func(state, k1);
        for (int j = 0; j < 3; j++) temp[j] = state[j] + k1[j] * H / 2;

        der_func(temp, k2);
        for (int j = 0; j < 3; j++) temp[j] = state[j] + k2[j] * H / 2;

        der_func(temp, k3);
        for (int j = 0; j < 3; j++) temp[j] = state[j] + k3[j] * H;

        der_func(temp, k4);
        for (int j = 0; j < 3; j++) state[j] = state[j] + H / 6 * (k1[j] + 2 * k2[j] + 2 * k3[j] + k4[j]);

        t +=H;
    }
}

int main() {
    double init_val[3] = {0, 0, 0.1};

    simulate(init_val);

    return 0;
}