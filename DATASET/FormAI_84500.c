//FormAI DATASET v1.0 Category: Temperature monitor ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  // Generate a random temperature between -10 and 50 degrees Celsius.
  srand(time(NULL));
  int temperature = rand() % 61 - 10;
  
  // Display the temperature to the user.
  printf("Current temperature: %d degrees Celsius\n", temperature);
  
  // Check if the temperature is below freezing point.
  if (temperature < 0) 
  {
    printf("Current temperature is below freezing point! Please stay warm and safe.\n");
  }
  else 
  {
    printf("Current temperature is normal. Have a great day!\n");
  }
  
  return 0;
}