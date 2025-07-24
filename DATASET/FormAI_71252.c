//FormAI DATASET v1.0 Category: Weather simulation ; Style: artistic
#include <stdio.h> 
#include <time.h>
#include <stdlib.h>

int main() {
  // randomly generate temperature between -10 to 40 degrees Celsius
  int temp = rand() % 51 - 10;

  // randomly select weather condition
  int condition = rand() % 3;

  // randomly select time of day
  int time = rand() % 2;

  // convert time to string
  char* time_str;
  if (time == 0) {
    time_str = "morning";
  } else {
    time_str = "evening";
  }

  printf("Good %s! The temperature today is %d degrees Celsius.\n", time_str, temp);

  if (condition == 0) {
    printf("It's a beautiful day! The sun is shining and there are no clouds in the sky.\n");
  } else if (condition == 1) {
    printf("It's a bit cloudy today. There might be some rain later.\n");
  } else {
    printf("It's raining outside. Make sure to bring an umbrella with you if you're going out.\n");
  }

  return 0;
}