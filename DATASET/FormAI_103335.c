//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: inquisitive
#include <stdio.h>

int main()
{
    float voltage, resistance, current;

    printf("Enter the voltage(V): ");
    scanf("%f", &voltage);

    printf("Enter the resistance(ohms): ");
    scanf("%f", &resistance);

    current = voltage / resistance;

    printf("The current flowing through the circuit is %f amps\n", current);

    return 0;
}