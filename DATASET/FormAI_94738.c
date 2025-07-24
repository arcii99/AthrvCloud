//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: distributed
#include <stdio.h>
#include <stdlib.h>

// Definition of the circuit structure
struct circuit {
    int id;
    float resistance;
    float voltage;
    float current;
};

int main() {
    // Initialization of the circuit variables
    struct circuit cir1 = {1, 100.0, 0, 0};
    struct circuit cir2 = {2, 200.0, 0, 0};
    struct circuit cir3 = {3, 300.0, 0, 0};
    struct circuit cir4 = {4, 400.0, 0, 0};
    
    // Calculation of the total resistence and voltage
    float total_resistance = (1/cir1.resistance) + (1/cir2.resistance) + (1/cir3.resistance) + (1/cir4.resistance);
    float total_voltage = 12.0;
    
    // Calculation of the current in each circuit
    cir1.current = total_voltage / (cir1.resistance * total_resistance);
    cir2.current = total_voltage / (cir2.resistance * total_resistance);
    cir3.current = total_voltage / (cir3.resistance * total_resistance);
    cir4.current = total_voltage / (cir4.resistance * total_resistance);
    
    // Display of the circuit values
    printf("Circuit %d values:\n Resistance: %f Ohms\n Voltage: %f V\n Current: %f A\n\n", cir1.id, cir1.resistance, cir1.voltage, cir1.current);
    printf("Circuit %d values:\n Resistance: %f Ohms\n Voltage: %f V\n Current: %f A\n\n", cir2.id, cir2.resistance, cir2.voltage, cir2.current);
    printf("Circuit %d values:\n Resistance: %f Ohms\n Voltage: %f V\n Current: %f A\n\n", cir3.id, cir3.resistance, cir3.voltage, cir3.current);
    printf("Circuit %d values:\n Resistance: %f Ohms\n Voltage: %f V\n Current: %f A\n\n", cir4.id, cir4.resistance, cir4.voltage, cir4.current);
    
    return 0;
}