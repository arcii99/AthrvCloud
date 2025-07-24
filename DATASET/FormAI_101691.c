//FormAI DATASET v1.0 Category: Weather simulation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int i, j, max_temp, min_temp, rand_temp;
  int weather[7][24];

  srand(time(NULL)); //seed random number generator

  //Generate random temperatures for each hour of each day
  for (i = 0; i < 7; i++) {
    for (j = 0; j < 24; j++) {
      rand_temp = rand() % 50; //Generate random temperature between 0 and 49 degrees Celsius
      weather[i][j] = rand_temp - 10; //Convert to Celsius and store in array
    }
  }

  //Determine maximum and minimum temperature for each day
  for (i = 0; i < 7; i++) {
    max_temp = -100;
    min_temp = 100;
    for (j = 0; j < 24; j++) {
      if (weather[i][j] > max_temp) {
        max_temp = weather[i][j];
      }
      if (weather[i][j] < min_temp) {
        min_temp = weather[i][j];
      }
    }
    //Print out maximum and minimum temperature for each day
    printf("Day %d: Maximum temperature is %d, Minimum temperature is %d\n", i+1, max_temp, min_temp);
  }

  //Determine average temperature for each hour of the week
  for (j = 0; j < 24; j++) {
    int sum = 0;
    for (i = 0; i < 7; i++) {
      sum += weather[i][j];
    }
    //Print out average temperature for each hour of the week
    printf("Hour %d: Average temperature is %d\n", j+1, sum/7);
  }

  return 0;
}