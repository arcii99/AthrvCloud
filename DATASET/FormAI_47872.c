//FormAI DATASET v1.0 Category: Weather simulation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(0));
  int count = 1;
  int temp = rand() % 100 + 1;
  int wind_speed = rand() % 20 + 1;
  char direction[4][7] = {"North", "East", "South", "West"};
  char sky_condition[3][9] = {"Clear", "Cloudy", "Rainy"};

  printf("Today's Weather Report:\n");
  printf("Temperature: %d degrees Celsius.\n", temp);
  printf("Wind Speed: %d m/s %s.\n", wind_speed, direction[rand() % 4]);
  printf("Sky Condition: %s.\n", sky_condition[rand() % 3]);

  while(count <= 10) {
    // Simulate change in weather over time
    temp += rand() % 10 - 5;
    wind_speed += rand() % 6 - 3;

    if(wind_speed <= 0) {
      wind_speed = 1;
    }

    if(temp < 0) {
      printf("WARNING! Temperature has dropped to %d degrees Celsius. Snowfall expected.\n", temp);
    } else if(temp > 30) {
      printf("WARNING! Temperature has risen to %d degrees Celsius. Heatwave warning.\n", temp);
    }

    // Print updated weather report
    printf("Weather update %d:\n", count);
    printf("Temperature: %d degrees Celsius.\n", temp);
    printf("Wind Speed: %d m/s %s.\n", wind_speed, direction[rand() % 4]);
    printf("Sky Condition: %s.\n", sky_condition[rand() % 3]);

    // Sleep for 2 seconds before next update
    sleep(2);
    count++;
  }

  printf("End of 10 updates. Thank you and stay safe.\n");

  return 0;
}