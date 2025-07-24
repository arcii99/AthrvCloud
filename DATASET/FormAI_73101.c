//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: safe
#include<stdio.h>

struct Circuit {
    char name[20];
    float resistance;
    float voltage;
    float current;
};

int main() {
    //creating the circuit
    struct Circuit circuit1;
    printf("Enter circuit name: ");
    scanf("%s", circuit1.name);
    printf("Enter circuit resistance in ohms: ");
    scanf("%f", &circuit1.resistance);
    printf("Enter circuit voltage in volts: ");
    scanf("%f", &circuit1.voltage);
    //calculating circuit current
    circuit1.current = circuit1.voltage / circuit1.resistance;
    //displaying circuit values
    printf("Circuit: %s\n", circuit1.name);
    printf("Resistance: %.2f ohms\n", circuit1.resistance);
    printf("Voltage: %.2f volts\n", circuit1.voltage);
    printf("Current: %.2f amps\n", circuit1.current);
    return 0;
}