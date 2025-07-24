//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: light-weight
#include <stdio.h>

int main() {
    // Define circuit parameters
    float voltage = 10;  // V
    float resistance = 1000;  // Ohms

    // Calculate circuit current
    float current = voltage / resistance;  // A

    // Calculate power dissipated by the resistor
    float power = voltage * current;  // W

    // Display results
    printf("Circuit Parameters:\n");
    printf("Voltage: %.2f V\n", voltage);
    printf("Resistance: %.2f Ohms\n", resistance);
    printf("\n");
    printf("Calculated Results:\n");
    printf("Current: %.4f A\n", current);
    printf("Power: %.4f W\n", power);

    return 0;
}