//FormAI DATASET v1.0 Category: Weather simulation ; Style: visionary
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main() {
  srand(time(0)); // Seed the random number generator with the current time
  
  // Temperature range
  int max_temp = 35; // Celsius
  int min_temp = -20; // Celsius
  
  // Probability of precipitation
  float precipitation_probability = 0.20; // Percent
  
  // Humidity range
  int max_humidity = 100; // Percent
  int min_humidity = 30; // Percent
  
  // Wind speed range
  int max_wind_speed = 50; // km/h
  int min_wind_speed = 0; // km/h
  
  // Weather conditions
  char * weather_conditions[] = {"Sunny", "Cloudy", "Rainy", "Snowy", "Stormy"};
  int num_weather_conditions = 5;
  
  // Generate weather data for the next 7 days
  printf("7 Day Weather Forecast:\n");
  for(int i = 0; i < 7; i++){
    // Generate random temperature within range
    int temperature = (rand() % (max_temp - min_temp + 1)) + min_temp;
    
    // Generate random precipitation
    int is_raining = (rand() % 100) < (precipitation_probability * 100);
    
    // Generate random humidity within range
    int humidity = (rand() % (max_humidity - min_humidity + 1)) + min_humidity;
    
    // Generate random wind speed within range
    int wind_speed = (rand() % (max_wind_speed - min_wind_speed + 1)) + min_wind_speed;
    
    // Select a random weather condition from the list
    int weather_condition_index = rand() % num_weather_conditions;
    
    // Print the weather data for the day
    printf("Day %d: %s, %dC, %d%% humidity, Wind %dkm/h", i+1, weather_conditions[weather_condition_index], temperature, humidity, wind_speed);
    
    // Print precipitation data if applicable
    if(is_raining){
      printf(", Rainy!\n");
    } else {
      printf("\n");
    }
  }
  
  return 0;
}