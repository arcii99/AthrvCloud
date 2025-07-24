//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: scientific
#include<stdio.h>
#include<math.h>

// Function to calculate impedance of a capacitor
float cap_impedance(float capacitance, float frequency){
  float impedance;
  impedance = 1 / (2 * M_PI * frequency * capacitance);
  return impedance;
}

// Function to calculate impedance of an inductor
float ind_impedance(float inductance, float frequency){
  float impedance;
  impedance = 2 * M_PI * frequency * inductance;
  return impedance;
}

int main(){
  float frequency, capacitance, inductance, resistance;
  printf("Enter the frequency in Hz: ");
  scanf("%f", &frequency);
  printf("Enter the capacitance in Farads: ");
  scanf("%f", &capacitance);
  printf("Enter the inductance in Henrys: ");
  scanf("%f", &inductance);
  printf("Enter the resistance in Ohms: ");
  scanf("%f", &resistance);

  // Calculate the impedances of capacitor and inductor
  float cap_imp, ind_imp;
  cap_imp = cap_impedance(capacitance, frequency);
  ind_imp = ind_impedance(inductance, frequency);

  // Calculate total impedance of the circuit
  float impedance = sqrt(pow(resistance, 2) + pow((ind_imp - cap_imp), 2));
  printf("Impedance of the circuit is: %f ohms", impedance);

  return 0;
}