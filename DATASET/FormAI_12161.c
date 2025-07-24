//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: grateful
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MAX(a,b) ((a>b)?a:b) 

int main()
{
    // define values for resistance, capacitance, and voltage
    float R1, R2, R3, R4, R5, R6, C1, C2, V1;
  
    // get input values from user
    printf("Enter the values of R1, R2, R3, R4, R5, R6, C1, C2, and V1:\n");
    scanf("%f%f%f%f%f%f%f%f%f", &R1, &R2, &R3, &R4, &R5, &R6, &C1, &C2, &V1);

    // define variables for voltage and current
    float V2, V3, V4, V5, V6, I1, I2, I3, I4, I5, I6;

    // initialize voltage variables to zero
    V2 = V3 = V4 = V5 = V6 = 0;

    // calculate current through resistor R1
    I1 = V1 / R1;

    // calculate voltage across capacitor C1
    V4 = I1 / (C1 * 2 * 3.14);

    // calculate current through resistor R2
    I2 = V4 / R2;

    // calculate voltage across capacitor C2
    V5 = I2 / (C2 * 2 * 3.14);

    // calculate current through resistor R3
    I3 = (V5 - V6) / R3;

    // calculate voltage at node 2
    V2 = V4 - R2 * I2;

    // calculate voltage at node 3
    V3 = V5 - R3 * I3;

    // calculate current through resistor R4
    I4 = (V3 - V4) / R4;

    // calculate voltage at node 6
    V6 = V4 + I4 * R5;

    // calculate current through resistor R6
    I6 = V6 / R6;

    // print the results
    printf("I1 = %.4fA\n", I1);
    printf("I2 = %.4fA\n", I2);
    printf("I3 = %.4fA\n", I3);
    printf("I4 = %.4fA\n", I4);
    printf("I6 = %.4fA\n", I6);

    printf("V2 = %.4fV\n", V2);
    printf("V3 = %.4fV\n", V3);
    printf("V4 = %.4fV\n", V4);
    printf("V5 = %.4fV\n", V5);
    printf("V6 = %.4fV\n", V6);

    return 0;
}