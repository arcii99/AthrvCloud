//FormAI DATASET v1.0 Category: Weather simulation ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int main()
{
  srand(time(NULL));   // seed random number generator
  
  int temperature = 20;
  bool is_raining = false;
  int humidity = 50;
  
  printf("Initial conditions:\n");
  printf("Temperature: %dC\n", temperature);
  printf("Rain: %s\n", is_raining ? "Yes" : "No");
  printf("Humidity: %d%%\n\n", humidity);
  
  for(int i = 0; i < 5; i++)   // simulate weather for 5 days
  {
    // generate random temperature change between -5C to 5C
    int temp_change = rand() % 11 - 5;
    temperature += temp_change;
    
    // generate random rainfall probability (40% chance of rain)
    int rain_prob = rand() % 100;
    is_raining = rain_prob < 40;
    
    // generate random humidity change between -10% to 10%
    int humid_change = rand() % 21 - 10;
    humidity += humid_change;
    
    // limit humidity to between 0% to 100%
    if(humidity > 100) humidity = 100;
    else if(humidity < 0) humidity = 0;
    
    printf("Day %d weather:\n", i+1);
    printf("Temperature: %dC (%s%d)\n", temperature, temp_change > 0 ? "+" : "", temp_change);
    printf("Rain: %s\n", is_raining ? "Yes" : "No");
    printf("Humidity: %d%% (%s%d%%)\n\n", humidity, humid_change > 0 ? "+" : "", humid_change);
  }
  
  return 0;
}