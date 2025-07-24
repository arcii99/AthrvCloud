//FormAI DATASET v1.0 Category: Smart home automation ; Style: random
//Welcome to Smart Home Automation!
//The following program controls the temperature and lighting of a smart home in real-time.

#include <stdio.h>

int main() {

  float currentTemp = 72.5;
  float desiredTemp = 70.0;
  int currentLight = 50;
  int desiredLight = 75;
  
  //Temperature Control
  
  if (currentTemp > desiredTemp) {
    printf("Current temperature: %.2f degrees Fahrenheit\n", currentTemp);
    printf("Lowering temperature...\n");
    currentTemp -= 0.5;
    printf("New temperature: %.2f degrees Fahrenheit\n", currentTemp);
  }
  else if (currentTemp < desiredTemp) {
    printf("Current temperature: %.2f degrees Fahrenheit\n", currentTemp);
    printf("Raising temperature...\n");
    currentTemp += 0.5;
    printf("New temperature: %.2f degrees Fahrenheit\n", currentTemp);
  }
  else {
    printf("Current temperature: %.2f degrees Fahrenheit\n", currentTemp);
    printf("Temperature is at desired level.\n");
  }
  
  //Lighting Control
  
  if (currentLight > desiredLight) {
    printf("Current light level: %d\n", currentLight);
    printf("Dimming lights...\n");
    currentLight -= 5;
    printf("New light level: %d\n", currentLight);
  }
  else if (currentLight < desiredLight) {
    printf("Current light level: %d\n", currentLight);
    printf("Brightening lights...\n");
    currentLight += 5;
    printf("New light level: %d\n", currentLight);
  }
  else {
    printf("Current light level: %d\n", currentLight);
    printf("Lighting is at desired level.\n");
  }
  
  //Loop back for continuous monitoring and control
  
  while(1) {
    //Code for real-time control goes here
  }
  
  return 0;
}