//FormAI DATASET v1.0 Category: Temperature monitor ; Style: creative
//Welcome to the Temperature Monitor Program!

#include <stdio.h>

int main() {
  float temperature, maxTemp = -273, minTemp = 1000; //initialize maximum and minimum temperatures

  printf("Enter the temperatures: ");

  for(int i=1; i<=5; i++){ //for loop to input and monitor temperatures
    scanf("%f", &temperature);
    if(temperature > maxTemp){
      maxTemp = temperature; //update maximum temperature
    }
    if(temperature < minTemp){
      minTemp = temperature; //update minimum temperature
    }
    printf("Temperature #%d: %.2f\n", i, temperature); //display input temperature
  }

  printf("\nMaximum Temperature: %.2f\n", maxTemp); //display maximum temperature
  printf("Minimum Temperature: %.2f\n", minTemp); //display minimum temperature

  return 0;
}