//FormAI DATASET v1.0 Category: Smart home automation ; Style: scientific
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>

int main(){
  
  //Initializing random seed
  srand(time(0));
  
  //Initializing devices
  bool light1 = false;  //Light 1
  bool light2 = false;  //Light 2
  bool fan = false;     //Fan
  
  //Randomly generating room temperature
  int temperature = (rand() % 10) + 20;
  
  //Displaying initial status
  printf("Initial Status:\n");
  printf("Temperature: %d degree Celsius\n", temperature);
  printf("Light 1: %s\n", light1?"On":"Off");
  printf("Light 2: %s\n", light2?"On":"Off");
  printf("Fan: %s\n", fan?"On":"Off");
  printf("\n");
  
  //Modifying status based on temperature
  if (temperature > 25) {
    fan = true;
  }
  if (temperature < 20) {
    light1 = true;
  }
  if (temperature < 15) {
    light2 = true;
  }
  
  //Displaying final status
  printf("Final Status:\n");
  printf("Temperature: %d degree Celsius\n", temperature);
  printf("Light 1: %s\n", light1?"On":"Off");
  printf("Light 2: %s\n", light2?"On":"Off");
  printf("Fan: %s\n", fan?"On":"Off");

  return 0;
}