//FormAI DATASET v1.0 Category: Smart home light control ; Style: statistical
#include <stdio.h>

int main() {
  int lightStatus = 0; // Variable to hold light status
  
  printf("Welcome to Smart Home Light Control!\n");
  printf("Press 1 to turn on the light or 0 to turn it off.\n");

  while(1) { // Continuously ask for input
    scanf("%d", &lightStatus); // Get user input
    
    if(lightStatus == 1) {
      printf("Light turned on.\n");
      // Code to turn on light using smart home technology
    }
    else if(lightStatus == 0) {
      printf("Light turned off.\n");
      // Code to turn off light using smart home technology
    }
    else {
      printf("Invalid input. Press 1 to turn on the light or 0 to turn it off.\n");
    }
  }

  return 0;
}