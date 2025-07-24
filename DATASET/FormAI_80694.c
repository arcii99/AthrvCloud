//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

//function to calculate resistance of a resistor
float calc_resistance(float voltage, float current)
{
    float resistance = voltage / current;
    return resistance;
}

//function to calculate capacitance of a capacitor
float calc_capacitance(float voltage, float frequency, float reactance)
{
    float capacitance = 1 / (2 * 3.14 * frequency * reactance) - 1 / voltage;
    return capacitance;
}

//main function
int main()
{
    //initialize variables
    float voltage, current, resistance, frequency, reactance, capacitance;

    //ask user for input
    printf("Enter voltage: ");
    scanf("%f", &voltage);

    printf("\nEnter current: ");
    scanf("%f", &current);

    printf("\nEnter frequency: ");
    scanf("%f", &frequency);

    printf("\nEnter reactance: ");
    scanf("%f", &reactance);

    //calculate resistance and capacitance
    resistance = calc_resistance(voltage, current);
    capacitance = calc_capacitance(voltage, frequency, reactance);

    //print results
    printf("\nResistance: %f", resistance);
    printf("\nCapacitance: %f", capacitance);

    return 0;
}