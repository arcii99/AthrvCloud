//FormAI DATASET v1.0 Category: Weather simulation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

  //declaring variables
  int temperature, humidity, wind_speed;
  
  //seed for random number generator
  time_t t;
  srand((unsigned) time(&t));
  
  //randomly generating values for temperature, humidity and wind speed
  temperature = rand() % 101; //temperature range: 0-100°C
  humidity = rand() % 101; //humidity range: 0-100%
  wind_speed = rand() % 101; //wind speed range: 0-100 km/h
  
  //displaying current weather conditions
  printf("Current weather conditions:\n");
  printf("Temperature: %d°C\n", temperature);
  printf("Humidity: %d%%\n", humidity);
  printf("Wind Speed: %d km/h\n", wind_speed);
  
  //checking for extreme weather conditions
  if(temperature >= 90) {
    printf("It's extremely hot outside. Avoid going out unless necessary.\n");
  }
  else if(temperature <= 10) {
    printf("It's extremely cold outside. Bundle up before going out.\n");
  }
  
  if(humidity >= 80) {
    printf("It's very humid outside. Stay indoors if possible.\n");
  }
  
  if(wind_speed >= 60) {
    printf("It's very windy outside. Be careful while driving or walking.\n");
  }
  
  //suggesting appropriate attire
    if(temperature >= 25) {
        printf("It's hot outside. Wear light, breathable clothes.\n");
    }
    else if(temperature >= 15 && temperature <= 24) {
        printf("It's warm outside. Wear comfortable clothes.\n");
    }
    else if(temperature >= 5 && temperature <= 14) {
        printf("It's cool outside. Wear a light jacket.\n");
    }
    else {
        printf("It's cold outside. Wear a heavy jacket.\n");
    }
    
  //suggesting appropriate activities
    if(temperature >= 25 && humidity <= 70) {
        printf("It's a perfect day for a swim.\n");
    }
    else if(temperature <= 15) {
        printf("It's a great day to curl up with a good book.\n");
    }
    else {
        printf("It's a good day to go for a walk or run.\n");
    }
    
    return 0;
}