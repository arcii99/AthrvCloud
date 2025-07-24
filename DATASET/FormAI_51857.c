//FormAI DATASET v1.0 Category: Weather simulation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {

  int temperature_array[24] = {0};
  double humidity_array[24] = {0};
  
  srand(time(NULL)); // seeding the random number generator with the current time

  printf("24-hour weather simulation:\n");
  printf("---------------------------\n");
  
  for(int i=0; i<24; i++) {
    
    int temperature = (rand() % 30) - 10; // temperatures range from -10 to 20 degrees Celsius
    
    double humidity = (double)rand() / RAND_MAX; // humidity is generated as a random number between 0 and 1

    temperature_array[i] = temperature;
    humidity_array[i] = humidity;
    
  }
  
  printf("Hour  Temperature (deg C)  Humidity\n");
  printf("------------------------------------\n");
  
  for(int i=0; i<24; i++) {
    
    printf("%2d    %15d     %0.2f\n", i, temperature_array[i], humidity_array[i]);
    
  }
  
  return 0;
}