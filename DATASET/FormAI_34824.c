//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: cheerful
#include <stdio.h>

int main() {
  printf("Welcome to the Joyful Circuit Simulator!\n");

  // Variable declaration
  int resistor, voltage;
  float current;

  // User input
  printf("Enter the value of the resistor in ohms: ");
  scanf("%d", &resistor);
  printf("Enter the value of the voltage in volts: ");
  scanf("%d", &voltage);

  // Calculation
  current = (float) voltage / resistor;

  // Output
  printf("The current flowing through the circuit is %.2f Amps.\n", current);

  printf("Thank you for using the Joyful Circuit Simulator! Have a fantastic day!\n");

  return 0;
}