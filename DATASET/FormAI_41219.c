//FormAI DATASET v1.0 Category: Temperature monitor ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

int main() {
  float tempArray[10] = {35.5, 36.0, 36.5, 37.0, 37.5, 38.0, 38.5, 39.0, 39.5, 40.0};
  char* tempStatus[10] = {"Freezing", "Cold", "Chilly", "Mild", "Warm", "Hot", "Very Hot", "Scorching", "Burning", "Melting"};
  int numTemps = sizeof(tempArray) / sizeof(tempArray[0]);
  int tempIndex = rand() % numTemps;
  
  printf("The current temperature is %f degrees Celsius. This is %s.\n", tempArray[tempIndex], tempStatus[tempIndex]);
  
  return 0;
}