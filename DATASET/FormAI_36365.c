//FormAI DATASET v1.0 Category: Weather simulation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(0)); // Seed the random function with current time

  // Random weather conditions
  int temperature = rand() % 51 - 10; // generates a random temperature between -10 and 40 degrees Celsius
  int humidity = rand() % 101; // generates a random humidity between 0 and 100 %
  int precipitation_type = rand() % 3; // 0 for no precipitation, 1 for rain, 2 for snow
  int precipitation_amount = rand() % 51; // generates a random precipitation amount between 0 and 50 mm

  // Print the weather conditions
  printf("Current weather conditions:\n");

  if (temperature < 0) {
    printf("Temperature: -%dC\n", -temperature);
  } else {
    printf("Temperature: %dC\n", temperature);
  }

  printf("Humidity: %d%%\n", humidity);

  if (precipitation_type == 0) {
    printf("Precipitation: None\n");
  } else if (precipitation_type == 1) {
    printf("Precipitation: Rain\n");
  } else {
    printf("Precipitation: Snow\n");
  }

  printf("Precipitation amount: %dmm\n", precipitation_amount);

  return 0;
}