//FormAI DATASET v1.0 Category: Unit converter ; Style: energetic
#include <stdio.h>

int main() {
  printf("Welcome to the Energetic Unit Converter!\n");
  printf("Let's start by choosing your current energy level.\n");
  
  double currentEnergy;
  printf("Enter your current energy level in Joules: ");
  scanf("%lf", &currentEnergy);
  
  printf("Your current energy level is %lf Joules.\n", currentEnergy);
  printf("Let's convert it to other energy units!\n");
  
  // Joules to Electron Volts
  double eV = currentEnergy / 1.602e-19;
  printf("Your current energy level is equivalent to %lf Electron Volts.\n", eV);
  
  // Joules to Kilowatt-Hours
  double kWh = currentEnergy / 3.6e+6;
  printf("Your current energy level is equivalent to %lf Kilowatt-Hours.\n", kWh);
  
  // Joules to Foot-Pounds
  double ftlb = currentEnergy / 1.36;
  printf("Your current energy level is equivalent to %lf Foot-Pounds.\n", ftlb);
  
  // Joules to Calories
  double cal = currentEnergy / 4.184;
  printf("Your current energy level is equivalent to %lf Calories.\n", cal);
  
  printf("Thank you for using the Energetic Unit Converter!\n");
  return 0;
}