//FormAI DATASET v1.0 Category: Weather simulation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

  srand(time(0));

  char weather[] = {'Sunny', 'Rainy', 'Foggy', 'Snowy'};
  int temperature;
  
  printf("Welcome to Weather Simulator!\n");

  for(int i=1; i<=7; i++) {

    int random_num = (rand() % 4);
    char* current_weather = weather[random_num];

    if(i==1){
      temperature = (rand() % 20) + 20 ;
    } else {
      int difference = (rand() % 5) - 2;
      temperature += difference;
    }

    printf("Day %d: ", i);
    printf("%s with a temperature of %d degrees Celsius.\n", current_weather, temperature);
  }

  printf("\nThat's it for this week's weather forecast!\n");

  return 0;
}