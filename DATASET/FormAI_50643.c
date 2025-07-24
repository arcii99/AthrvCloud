//FormAI DATASET v1.0 Category: Weather simulation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main() {
  int temps[365];
  int avg_high = 80;
  int avg_low = 35;
  int i;
  int hours_in_day = 24;
  srand(time(NULL));

  // initialize temps array
  for (i = 0; i < 365; i++) {
    temps[i] = (rand() % (avg_high - avg_low + 1)) + avg_low;
  }

  // simulate weather changes
  for (i = 0; i < 365; i++) {
    int change = (rand() % 10) - 5;
    temps[i] += change;
  }

  // determine the hottest and coldest days
  int hottest_day = 0;
  int coldest_day = 0;
  for (i = 0; i < 365; i++) {
    if (temps[i] > temps[hottest_day]) {
      hottest_day = i;
    }
    if (temps[i] < temps[coldest_day]) {
      coldest_day = i;
    }
  }

  // calculate annual average temperature
  int total_temp = 0;
  for (i = 0; i < 365; i++) {
    total_temp += temps[i];
  }
  int annual_avg_temp = total_temp / 365;

  // simulate the passing of days
  int days_passed = 0;
  int current_temp = temps[0];
  int current_hour = 0;
  while (days_passed < 365) {

    // simulate the passing of hours in a day
    for (i = 0; i < hours_in_day; i++) {
      printf("Day %d Hour %d: Temperature is %d degrees\n", days_passed + 1, current_hour, current_temp);
      int change = (rand() % 4) - 2;
      current_temp += change;
      if (current_temp > avg_high) {
        current_temp = avg_high;
      }
      if (current_temp < avg_low) {
        current_temp = avg_low;
      }
      current_hour++;
    }

    // reset hour at end of the day
    current_hour = 0;
    days_passed++;
    current_temp = temps[days_passed];
  }

  printf("Hottest day of the year: Day %d with temperature %d degrees\n", hottest_day + 1, temps[hottest_day]);
  printf("Coldest day of the year: Day %d with temperature %d degrees\n", coldest_day + 1, temps[coldest_day]);
  printf("Annual average temperature: %d degrees\n", annual_avg_temp);

  return 0;
}