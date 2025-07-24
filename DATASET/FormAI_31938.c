//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: enthusiastic
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// function to calculate resistance
double resistance(double r1, double r2){
    return r1 + r2;
}

// function to calculate capacitance
double capacitance(double c1, double c2){
    return c1 + c2;
}

// function to calculate inductance
double inductance(double l1, double l2){
    return l1 + l2;
}

// function to calculate impedance
double impedance(double r, double c, double l, double f){
    double w = 2 * M_PI * f;
    double x_c = 1 / (w * c);
    double x_l = w * l;
    return sqrt((r * r) + ((x_l - x_c) * (x_l - x_c)));
}

int main(){
    double r1, r2, c1, c2, l1, l2, f;
    printf("Enter the values for R1, R2, C1, C2, L1, L2 and f: ");
    scanf("%lf %lf %lf %lf %lf %lf %lf", &r1, &r2, &c1, &c2, &l1, &l2, &f);

    // calculate equivalent resistance, capacitance and inductance
    double r = resistance(r1, r2);
    double c = capacitance(c1, c2);
    double l = inductance(l1, l2);

    // calculate impedance
    double z = impedance(r, c, l, f);

    printf("The equivalent R, C and L values are: %.2lf, %.2lf and %.2lf\n", r, c, l);
    printf("The impedance of the circuit is: %.2lf\n", z);

    return 0;
}