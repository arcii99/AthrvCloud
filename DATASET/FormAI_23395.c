//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

int main() {
    
    printf("Welcome to ye olde circuit simulator!\n\n");

    int resistors, volts, amps;
    float total_resistance, power;

    printf("Enter the number of resistors in thine circuit: ");
    scanf("%d", &resistors);

    int resistor_array[resistors];

    for(int i = 1; i <= resistors; i++) {
        printf("Enter the resistance of resistor %d (in ohms): ", i);
        scanf("%d", &resistor_array[i-1]);
    }

    printf("\nEnter the voltage of thine circuit (in volts): ");
    scanf("%d", &volts);

    total_resistance = 0;

    for(int i = 0; i < resistors; i++) {
        total_resistance += (float)resistor_array[i];
    }

    total_resistance = 1/total_resistance;

    amps = volts / total_resistance;
    power = (float)volts * amps;
    
    printf("\nThy circuit hast a total resistance of %.2f ohms,\nflows at a current of %d amps,\nand consumes %f watts of power. \n\nFare thee well!", total_resistance, amps, power);

    return 0;
}