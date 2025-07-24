//FormAI DATASET v1.0 Category: Temperature monitor ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TEMP 50.0
#define MIN_TEMP -10.0

double getTemp() {
  double temp = MIN_TEMP + (rand() / (double)RAND_MAX) * (MAX_TEMP - MIN_TEMP);
  return temp;
}

double getHumidity() {
  double humidity = rand() / (double)RAND_MAX;
  return humidity;
}

double getPressure() {
  double pressure = 800 + (rand() / (double)RAND_MAX) * 400;
  return pressure;
}

int main() {
  srand(time(NULL));

  double currentTemp, currentHumidity, currentPressure;

  printf("Monitoring temperature, humidity, and pressure...\n\n");

  while (1) {
    currentTemp = getTemp();
    currentHumidity = getHumidity();
    currentPressure = getPressure();

    printf("Temperature: %.1fC\n", currentTemp);
    printf("Humidity: %.2f%%\n", currentHumidity * 100);
    printf("Pressure: %.2fhPa\n", currentPressure);

    printf("\n");
    sleep(5);
  }

  return 0;
}