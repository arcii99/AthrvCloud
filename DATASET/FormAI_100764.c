//FormAI DATASET v1.0 Category: Weather simulation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  char *weather_conditions[] = {"sunny", "cloudy", "rainy", "foggy", "snowy"};
  srand(time(NULL));
  int random_index = rand() % 5;
  printf("Today's weather condition is %s\n", weather_conditions[random_index]);
  return 0;
}