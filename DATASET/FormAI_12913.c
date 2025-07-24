//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: energetic
#include <stdio.h>

// Circuit components enumeration
typedef enum {
  RESISTOR,
  CAPACITOR,
  INDUCTOR,
  VOLTAGE_SOURCE
} ComponentType;

// Circuit component struct
typedef struct {
  ComponentType type;
  double value;
  double voltage;
  double current;
} Component;

// Main function
int main() {

  // Create circuit components
  Component resistor1 = {RESISTOR, 1000.0, 0.0, 0.0};
  Component resistor2 = {RESISTOR, 2000.0, 0.0, 0.0};
  Component capacitor1 = {CAPACITOR, 0.001, 0.0, 0.0};
  Component inductor1 = {INDUCTOR, 0.01, 0.0, 0.0};
  Component voltage_source1 = {VOLTAGE_SOURCE, 5.0, 0.0, 0.0};

  // Define simulation parameters
  double time_step = 0.0001; // 0.1 millisecond time step
  double simulation_time = 0.1; // 100 millisecond simulation time

  // Run simulation
  for (double time = 0.0; time < simulation_time; time += time_step) {

    // Update component voltages and currents
    resistor1.voltage = voltage_source1.voltage - resistor2.voltage;
    resistor2.voltage = resistor1.voltage;
    resistor1.current = resistor1.voltage / resistor1.value;
    resistor2.current = resistor2.voltage / resistor2.value;
    capacitor1.current = capacitor1.voltage / capacitor1.value;
    inductor1.current = inductor1.voltage / inductor1.value;

    // Calculate new voltage across capacitor
    double new_voltage = capacitor1.voltage + (1/capacitor1.value) * (resistor2.current - capacitor1.current) * time_step;

    // Check for voltage changes greater than 10%
    if ((new_voltage - capacitor1.voltage) / capacitor1.voltage > 0.1 || (new_voltage - capacitor1.voltage) / capacitor1.voltage < -0.1) {
      printf("Voltage across capacitor1 has changed by more than 10%% at t=%lf\n", time);
    }

    // Update component voltage and reset current
    capacitor1.voltage = new_voltage;
    capacitor1.current = 0.0;

    // Print component voltages and currents
    printf("t=%lf, V1=%lf, V2=%lf, Vc=%lf, Il=%lf, Ir1=%lf, Ir2=%lf\n", time, voltage_source1.voltage, resistor2.voltage, capacitor1.voltage, inductor1.current, resistor1.current, resistor2.current);
  }

  return 0;
}