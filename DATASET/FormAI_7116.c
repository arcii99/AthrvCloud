//FormAI DATASET v1.0 Category: Temperature monitor ; Style: retro
#include <stdio.h>
#include <stdlib.h>

void main() {
  float temperature = 26.0;
  int i = 0;
  while (1) {
    system("cls");
    printf("*********************************************\n");
    printf("*                                           *\n");
    printf("*               TEMPERATURE MONITOR          *\n");
    printf("*                                           *\n");
    printf("*********************************************\n");
    printf("*                                           *\n");
    printf("*  Current Temperature: %.2f%cC        *\n", temperature, 248);
    printf("*                                           *\n");
    printf("*********************************************\n");
    
    // Randomly change the temperature
    if (i % 3 == 0) {
      temperature += 0.5;
    } else if (i % 3 == 1) {
      temperature -= 0.3;
    }
    
    // Pause for 1 second
    int j;
    for (j = 0; j < 100000000; j++);
    
    // Increment counter
    i++;
  }
}