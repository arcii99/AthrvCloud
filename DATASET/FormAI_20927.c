//FormAI DATASET v1.0 Category: Weather simulation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int temperature[7];
  int humidity[7];
  char* daysOfWeek[7] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
  
  srand(time(NULL)); //seed the randomizer
  
  //generate random data for temperature and humidity for each day of the week 
  for(int i = 0; i < 7; i++) {
    temperature[i] = rand() % 30;
    humidity[i] = rand() % 100;
  }
  
  //display the weather for each day of the week
  printf("\n\nDaily Weather Simulation\n\n");
  for(int i = 0; i < 7; i++) {
    printf("%s's Weather: Temperature %d degrees Celsius and Humidity %d%%\n", daysOfWeek[i], temperature[i], humidity[i]);
  }
  
  return 0;
}