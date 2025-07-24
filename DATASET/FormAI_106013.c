//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define R1 1000 //Resistor value in ohms
#define R2 2200 //Resistor value in ohms
#define C1 0.001 //Capacitor value in farads

double voltage(double t) {
    return 5.0 * exp(-t / (R1 * C1)) * (1 - exp(-t / (R2 * C1)));
}

int main() {
    double t, v;
    FILE* fp;
    char filename[] = "output.txt";
    fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    for (t = 0; t <= 10; t += 0.1) {
        v = voltage(t);
        fprintf(fp, "%f %f\n", t, v);
    }
    fclose(fp);
    return 0;
}