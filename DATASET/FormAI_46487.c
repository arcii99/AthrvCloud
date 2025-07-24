//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define PI 3.14159265

// function to generate random network traffic values
double createRandomTrafficValue() {
  double randomValue = (double)rand() / RAND_MAX;  // generate random number between 0 and 1
  double trafficValue = 10 * sin(2 * PI * randomValue);  // apply sin function to create traffic patterns
  return trafficValue;
}

int main() {
  srand(time(NULL));  // initialize random seed

  printf("Welcome to the Network QoS Monitor!\n");
  printf("Press any key to start monitoring the network...\n");
  getchar();  // waits for user input before continuing

  int counter = 0;

  while (1) {  // program runs indefinitely until user manually stops it
    double currentTraffic = createRandomTrafficValue();
    printf("Current network traffic QoS value: %f\n", currentTraffic);
    counter++;

    if (counter % 10 == 0) {  // every 10 iterations, provide a surreal message
      switch (rand() % 3) {  // randomly choose from 3 different messages
        case 0:
          printf("The packet lords smile upon us...\n");
          break;
        case 1:
          printf("Interdimensional interference detected!...\n");
          break;
        case 2:
          printf("The network's soul is being cleansed...\n");
          break;
      }
    }

    sleep(1);  // wait for 1 second before repeating loop
  }

  return 0;
}