//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: shocked
#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

typedef struct {
    double resistance;
    double capacitance;
    double inductance;
} circuit;

double impedance(circuit c, double frequency) {
    double reactance_capacitor = 1.0 / (2 * PI * frequency * c.capacitance);
    double reactance_inductor = 2 * PI * frequency * c.inductance;
    double total_impedance = sqrt(c.resistance*c.resistance + pow(reactance_inductor-reactance_capacitor, 2));
    return total_impedance;
}

int main() {
    circuit c;
    double freq;
    printf("Enter resistance (ohms): ");
    scanf("%lf", &c.resistance);
    printf("Enter capacitance (farads): ");
    scanf("%lf", &c.capacitance);
    printf("Enter inductance (henries): ");
    scanf("%lf", &c.inductance);
    printf("Enter frequency (hertz): ");
    scanf("%lf", &freq);
    double total_impedance = impedance(c, freq);
    printf("Total Impedance: %lf ohms", total_impedance);
    return 0;
}