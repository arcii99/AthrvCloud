//FormAI DATASET v1.0 Category: Smart home automation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int temperature = 0;
  int humidity = 0;
  int light = 0;
  int windowStatus = 0;
  int doorStatus = 0;

  //Initialize the random number generator
  srand(time(0));

  //Simulate the sensor readings
  temperature = rand() % 100;
  humidity = rand() % 100;
  light = rand() % 100;

  //Check the status of the window and door
  windowStatus = 1;  //Window is closed
  doorStatus = 0;    //Door is open

  //Display the initial status of the smart home system
  printf("Smart Home Automation\n");
  printf("----------------------\n");
  printf("Temperature: %d C\n", temperature);
  printf("Humidity: %d %%\n", humidity);
  printf("Light: %d %%\n", light);
  printf("Window Status: %s\n", windowStatus ? "Closed" : "Open");
  printf("Door Status: %s\n", doorStatus ? "Closed" : "Open");

  //Control the window status
  if (temperature > 30 && windowStatus == 0) {
    windowStatus = 1; //Close the window
    printf("Window is Closed due to High Temperature!\n");
  } else if (temperature < 20 && windowStatus == 1) {
    windowStatus = 0; //Open the window
    printf("Window is Open due to Low Temperature!\n");
  } else {
    printf("Window Status is Not Changed!\n");
  }

  //Control the door status
  if (light < 10 && doorStatus == 0) {
    doorStatus = 1; //Close the door
    printf("Door is Closed due to Low Light!\n");
  } else if (light > 80 && doorStatus == 1) {
    doorStatus = 0; //Open the door
    printf("Door is Open due to High Light!\n");
  } else {
    printf("Door Status is Not Changed!\n");
  }

  //Display the final status of the smart home system
  printf("\nSmart Home Automation\n");
  printf("----------------------\n");
  printf("Temperature: %d C\n", temperature);
  printf("Humidity: %d %%\n", humidity);
  printf("Light: %d %%\n", light);
  printf("Window Status: %s\n", windowStatus ? "Closed" : "Open");
  printf("Door Status: %s\n", doorStatus ? "Closed" : "Open");

  return 0;
}