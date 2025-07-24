//FormAI DATASET v1.0 Category: Weather simulation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

  float temperature, humidity, rainfall;
  int i, j, month, day, year;
  
  srand(time(0)); // Set random seed
  
  printf("Enter a date (mm dd yyyy): ");
  scanf("%d %d %d", &month, &day, &year);
  
  printf("\nWEATHER FORCAST FOR %d/%d/%d\n\n", month, day, year);
  
  for (i = 1; i <= 5; i++) { // Simulate 5 days
    printf("Day %d:\n", i);
    
    for (j = 0; j < 24; j++) { // Simulate 1 day with 24 hours
      
      // Generate random values for temperature, humidity, and rainfall
      temperature = rand()%41 - 20; // range between -20 and 20 ˚C
      humidity = rand()%101; // range between 0 and 100%
      
      if (j == 0) { // Only print rainfall for the first hour of the day
        rainfall = rand()%11; // range between 0 and 10 mm
        printf("%d:00 - %d mm\n", j, (int)rainfall);
      } else {
        rainfall = rand()%3; // range between 0 and 2 mm
      }

      printf("%d:00 - %.1f ˚C, %.0f%%, %.1f mm\n", j, temperature, humidity, rainfall);
      
      // Simulate day-night cycle
      if (j == 23) {
        temperature -= 10; // temperature drops 10˚C at night
      }
    }
    printf("\n");
  }
  
  return 0;
}