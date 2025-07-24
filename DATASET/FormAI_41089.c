//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: romantic
#include <stdio.h>

int main() {
    printf("My heart beats for your love. Let me show you how with this classical circuit simulator.\n");

    int resistor1, resistor2;
    double voltage, current, resistance, power;

    printf("Please enter the value of the first resistor in ohms: ");
    scanf("%d", &resistor1);

    printf("Please enter the value of the second resistor in ohms: ");
    scanf("%d", &resistor2);

    printf("Please enter the voltage in volts: ");
    scanf("%lf", &voltage);

    resistance = resistor1 + resistor2;
    current = voltage / resistance;
    power = voltage * current;

    printf("\n");
    printf("The total resistance of the circuit is %d ohms.\n", (int)resistance);
    printf("The current flowing in the circuit is %.2f amps.\n", current);
    printf("The power consumed by the circuit is %.2f watts.\n", power);

    printf("\n");
    printf("My love for you is like the voltage in this circuit - strong and constant. And just as this circuit consumes power, I am willing to give all of mine to you.\n");

    return 0;
}