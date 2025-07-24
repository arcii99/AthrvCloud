//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: cheerful
#include <stdio.h>

int main() {
    printf("Hello, let's simulate some circuits!\n");

    // Define the input voltages
    float input_voltages[] = {2.5, 3.8, 5.0};

    // Define the resistors
    float resistors[] = {100, 220, 330, 470, 680, 1000};

    // Calculate the output voltage for each combination of inputs and resistors
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 6; j++) {
            float output_voltage = input_voltages[i] * resistors[j] / (resistors[j] + 1000);
            printf("Input voltage: %f V, Resistor: %f ohms, Output voltage: %f V\n", input_voltages[i], resistors[j], output_voltage);
        }
    }

    printf("Circuit simulation complete! Thank you for using our program.\n");

    return 0;
}