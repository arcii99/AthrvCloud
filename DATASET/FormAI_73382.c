//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: recursive
#include<stdio.h>
#include<stdlib.h>

// Function to calculate the power of a number
int power(int base, int exp) {
    if(exp == 0)
        return 1;
    else
        return base * power(base, exp-1);
}

// Function to calculate the total resistance in a given circuit
int total_resistance(int *resistances, int size) {
    if(size == 1)
        return *resistances;
    else
        return *(resistances + size-1) + 1/total_resistance(resistances, size-1);
}

int main() {
    int resistances[] = {10, 20, 30, 40};   // Resistances in ohms
    int size = sizeof(resistances)/sizeof(int);   // Size of array
    int total_res = total_resistance(resistances, size);

    printf("Total resistance of the circuit: %d ohms\n", total_res);

    int voltage = 10;   // Voltage in volts
    int current = voltage/total_res;
    printf("Current through the circuit: %d A\n", current);

    return 0;
}