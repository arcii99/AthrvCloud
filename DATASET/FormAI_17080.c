//FormAI DATASET v1.0 Category: Smart home automation ; Style: Dennis Ritchie
#include <stdio.h>

int main() {
  // Declare variables
  int temp = 0;
  int light = 0;
  int motion = 0;

  // Continuously read sensor data
  while(1) {
    // Simulate temperature sensor reading
    printf("Temperature reading: ");
    scanf("%d", &temp);

    // Simulate light sensor reading
    printf("Light reading: ");
    scanf("%d", &light);

    // Simulate motion sensor reading
    printf("Motion reading: ");
    scanf("%d", &motion);

    // Determine home automation actions based on sensor data
    if(temp > 80) {
      printf("Turning on AC...\n");
    }

    if(light < 50 && motion == 0) {
      printf("Turning off lights...\n");
    }

    if(motion == 1) {
      printf("Turning on lights...\n");
    }
  }

  return 0;
}