//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: calm
#include <stdio.h>

// Function prototypes
void redLight();
void yellowLight();
void greenLight();

int main() {
  int time, cycle = 0;
  
  while (1) {
    cycle++;
    printf("\nCycle %d\n", cycle);
    
    // RED light for 10 seconds
    redLight();
    
    // YELLOW light for 2 seconds
    yellowLight();
    
    // GREEN light for 15 seconds
    greenLight();
    
    // YELLOW light for 2 seconds before changing to RED
    yellowLight();
  }
  
  return 0;
}

void redLight() {
  int time = 0;
  printf("RED light is ON!\n");
  
  while (time < 10) {
    printf("%d seconds left in RED light.\n", 10 - time);
    time++;
    sleep(1); // Delay for 1 second
  }
  
  printf("RED light is turning OFF!\n");
}

void yellowLight() {
  int time = 0;
  printf("YELLOW light is ON!\n");
  
  while (time < 2) {
    printf("%d seconds left in YELLOW light.\n", 2 - time);
    time++;
    sleep(1); // Delay for 1 second
  }
  
  printf("YELLOW light is turning OFF!\n");
}

void greenLight() {
  int time = 0;
  printf("GREEN light is ON!\n");
  
  while (time < 15) {
    printf("%d seconds left in GREEN light.\n", 15 - time);
    time++;
    sleep(1); // Delay for 1 second
  }
  
  printf("GREEN light is turning OFF!\n");
}