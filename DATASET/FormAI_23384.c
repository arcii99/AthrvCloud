//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: beginner-friendly
#include <stdio.h>

// Define constants for circuit parameters
#define VCC 5.0
#define R1 1000.0
#define R2 2000.0
#define C 0.000001

// Function to calculate the voltage across C
double calculateVoltage(double time) {
  double vR1 = (VCC * R2) / (R1 + R2); // voltage across R1
  double vC = VCC - vR1; // voltage across C
  double deltaV = vC * (1 - exp(-time / (R1 * C))); // calculate voltage drop
  double V = VCC - deltaV; // calculate potential difference
  return V;
}

int main() {
  double time = 0.0;
  double voltage = calculateVoltage(time);

  // Loop through time values and print voltage across the capacitor
  while (time <= 0.01) {
    printf("Time: %fs Voltage: %fV\n", time, voltage);
    time += 0.000001;
    voltage = calculateVoltage(time);
  }

  return 0;
}