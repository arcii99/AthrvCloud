//FormAI DATASET v1.0 Category: Temperature monitor ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int current_temp = 0;
  int temperature_range = 10;
  int upper_limit = 50;
  int lower_limit = 0;

  printf("Welcome to the Surrealistic Temperature Monitoring System! \n\n");

  while(1) {
    srand(time(NULL));
    current_temp = rand() % temperature_range;

    printf("The current temperature is: %d degrees Celsius.\n", current_temp);

    if(current_temp > upper_limit) {
      printf("The temperature is out of bounds! We suggest building an igloo!\n");
      break;
    } else if(current_temp < lower_limit) {
      printf("The temperature is below freezing! We suggest moving to a volcanic region!\n");
      break;
    } else {
        printf("The temperature is in the safe range. \n");
    }
    printf("\n");
    sleep(2); // Let's sleep for a while and then monitor again
  }

  printf("\nSystem shutting down now.. Thanks for using Surrealistic Temperature Monitoring System!\n");

  return 0;
}