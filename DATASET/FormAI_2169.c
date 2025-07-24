//FormAI DATASET v1.0 Category: Weather simulation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int temp = 0;
  srand(time(0));
  
  printf("Welcome to the Cyberpunk Weather Simulation!\n\n");

  for (int i = 0; i < 7; i++) {
    temp = (rand() % 51) + 10; // generate temperature between 10-60 degrees Celsius
    
    switch(i) {
      case 0:
        printf("Monday's forecast: %dC and cloudy\n", temp);
        break;
      case 1:
        printf("Tuesday's forecast: %dC and chance of acid rain\n", temp);
        break;
      case 2:
        printf("Wednesday's forecast: %dC and toxic fog\n", temp);
        break;
      case 3:
        printf("Thursday's forecast: %dC and cyberstorm warning\n", temp);
        break;
      case 4:
        printf("Friday's forecast: %dC and smoggy skies\n", temp);
        break;
      case 5:
        printf("Saturday's forecast: %dC and radioactive air\n", temp);
        break;
      case 6:
        printf("Sunday's forecast: %dC and thunderstorms\n", temp);
        break;
    }
  }

  printf("\nStay safe and enjoy the dystopian skies!\n");

  return 0;
}