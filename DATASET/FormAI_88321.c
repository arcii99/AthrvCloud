//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: romantic
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

float c, r1, r2, t, v;
float pi = 3.14159265359;

int main()
{
    printf("\nWelcome to the Classical Circuit Simulator!\n");
    printf("This program will help you determine the voltage across the capacitor in a simple RC circuit\n\n");

    printf("Please enter the value of the capacitor in Farads: ");
    scanf("%f", &c);

    printf("Please enter the value of the first resistor in Ohms: ");
    scanf("%f", &r1);

    printf("Please enter the value of the second resistor in Ohms: ");
    scanf("%f", &r2);

    printf("Please enter the time in seconds for which you want to simulate the circuit: ");
    scanf("%f", &t);

    printf("\nCalculating voltage across capacitor...\n\n");

    v = (exp(-1*(t/(c*(r1+r2))))*((r2/(r1+r2))*10.0));

    printf("The voltage across the capacitor after %f seconds is %.2f volts\n\n", t, v);

    printf("Thank you for using the Classical Circuit Simulator\n");

    return 0;
}