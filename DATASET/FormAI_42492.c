//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265

typedef struct {
    double frequency;
    double phase;
    double amplitude;
} Signal;

typedef struct {
    double resistance;
    double capacitance;
} RC_Circuit;

double calculate_voltage(RC_Circuit circuit, Signal input) {
    double omega = 2 * PI * input.frequency;
    double impedance = 1 / (circuit.resistance * omega * circuit.capacitance);
    double current_amplitude = input.amplitude / impedance;
    double current_phase = input.phase + (PI / 2);
    double voltage_amplitude = current_amplitude * impedance;
    double voltage_phase = current_phase - (PI / 2);
    double voltage = voltage_amplitude * cos(voltage_phase);

    return voltage;
}

int main() {
    Signal input_signal;
    input_signal.frequency = 1000;
    input_signal.phase = PI / 4;
    input_signal.amplitude = 10;

    RC_Circuit circuit;
    circuit.resistance = 1000;
    circuit.capacitance = 0.000001;

    double voltage = calculate_voltage(circuit, input_signal);

    printf("The voltage across the RC circuit is %f volts.", voltage);

    return 0;
}