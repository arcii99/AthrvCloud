//FormAI DATASET v1.0 Category: Temperature monitor ; Style: sophisticated
#include<stdio.h>
#include<stdlib.h>

//Function to get the temperature data from sensor
double getTemperature() {
  double temperature = (double) rand() / RAND_MAX; //generating random temperature data
  temperature = (temperature * 100) - 50; //scaling temperature data to range of -50 to 50
  return temperature;
}

int main() {

  printf("Welcome to Temperature Monitor!\n\n");

  //Initializing variables to keep track of highest and lowest temperatures
  double highestTemp = -99;
  double lowestTemp = 99;

  //Generating temperature data for next 24 hours
  for(int i=0; i<24; i++) {
    double temperature = getTemperature();
    printf("Temperature at hour %d: %.2lf°C\n", i, temperature);

    //Updating highest and lowest temperature variables
    if(temperature > highestTemp) {
      highestTemp = temperature;
    }
    if(temperature < lowestTemp) {
      lowestTemp = temperature;
    }
  }

  //Printing highest and lowest temperatures for the day
  printf("\n\nHighest Temperature for the day: %.2lf°C\n", highestTemp);
  printf("Lowest Temperature for the day: %.2lf°C\n", lowestTemp);

  return 0;
}