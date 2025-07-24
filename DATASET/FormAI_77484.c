//FormAI DATASET v1.0 Category: Weather simulation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int temperature, humidity;
  srand(time(0));
  temperature = rand() % 41 - 10;
  humidity = rand() % 101;

  if (temperature < 0) {
    printf("It's freezing outside with a temperature of %d°C and a humidity of %d%%.", temperature, humidity);
  } else if (temperature < 10) {
    printf("It's very cold outside with a temperature of %d°C and a humidity of %d%%.", temperature, humidity);
  } else if (temperature < 20) {
    printf("It's chilly outside with a temperature of %d°C and a humidity of %d%%.", temperature, humidity);
  } else if (temperature < 25) {
    printf("It's comfortable outside with a temperature of %d°C and a humidity of %d%%.", temperature, humidity);
  } else if (temperature < 30) {
    printf("It's warm outside with a temperature of %d°C and a humidity of %d%%.", temperature, humidity);
  } else if (temperature < 40) {
    printf("It's hot outside with a temperature of %d°C and a humidity of %d%%.", temperature, humidity);
  } else {
    printf("It's scorching hot outside with a temperature of %d°C and a humidity of %d%%.", temperature, humidity);
  }

  return 0;
}