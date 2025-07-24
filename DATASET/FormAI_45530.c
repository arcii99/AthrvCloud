//FormAI DATASET v1.0 Category: Weather simulation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TEMPERATURE 40
#define MIN_TEMPERATURE -20

#define MAX_PRECIPITATION 30
#define MIN_PRECIPITATION 0

#define MAX_WIND_SPEED 120
#define MIN_WIND_SPEED 0

#define MAX_HUMIDITY 100
#define MIN_HUMIDITY 0

#define FALSE 0
#define TRUE 1

void simulate_weather(void);

int main(void) {
  simulate_weather();
  return 0;
}

void simulate_weather(void) {
  int temperature, precipitation, wind_speed, humidity;
  int i, max_iterations;
  int is_blizzard, is_tornado, is_flood;
  
  srand(time(0));
  max_iterations = rand() % 10 + 1;

  for(i = 0; i < max_iterations; i++) {
    temperature = rand() % (MAX_TEMPERATURE - MIN_TEMPERATURE + 1) + MIN_TEMPERATURE;
    precipitation = rand() % (MAX_PRECIPITATION - MIN_PRECIPITATION + 1) + MIN_PRECIPITATION;
    wind_speed = rand() % (MAX_WIND_SPEED - MIN_WIND_SPEED + 1) + MIN_WIND_SPEED;
    humidity = rand() % (MAX_HUMIDITY - MIN_HUMIDITY + 1) + MIN_HUMIDITY;

    is_blizzard = FALSE;
    is_tornado = FALSE;
    is_flood = FALSE;

    if(temperature < -10 && precipitation > 15 && wind_speed > 60) {
      printf("Heavy snowstorm warnings! Stay indoors!\n");
      is_blizzard = TRUE;
    }

    if(precipitation > 25 && wind_speed > 90 && humidity > 80) {
      printf("Tornado warnings! Seek shelter immediately!\n");
      is_tornado = TRUE;
    }

    if(precipitation > 20 && humidity > 90) {
      printf("Flood warnings! Evacuate if necessary!\n");
      is_flood = TRUE;
    }

    if(!is_blizzard && !is_tornado && !is_flood) {
      printf("Weather conditions are normal.\n");
    }
  }
}