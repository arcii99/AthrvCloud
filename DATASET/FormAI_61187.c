//FormAI DATASET v1.0 Category: Temperature monitor ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h> 

int main() {
  float temp; // temperature read-in value
  time_t t; // time variable
  srand((unsigned) time(&t)); // seed random number generator with current time

  printf("Temperature Monitor\n");

  while (1) { // run forever
    temp = (float)rand()/((float)RAND_MAX/50); // generate random temperature between 0 and 50 degrees Celsius
    printf("Current temperature: %.2fC\n", temp);
    sleep(1); // wait 1 second before generating new temperature reading
  }

  return 0; // exit main
}