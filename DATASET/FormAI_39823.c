//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRAVEL_LIMIT 1000000000

int main(){
  time_t current_time = time(NULL);
  printf("Current time: %s\n", ctime(&current_time));
  
  printf("Enter a year to time travel to (yyyy format): ");
  char input[5];
  fgets(input, 5, stdin);
  int target_year = atoi(input);
  
  int current_year = localtime(&current_time)->tm_year + 1900;
  if(target_year > current_year){
    printf("You can't travel to the future!\n");
    return 0;
  }
  
  int years_traveled = current_year - target_year;
  printf("Traveling %d years into the past...\n\n", years_traveled);
  
  time_t traveled_time = current_time - (years_traveled * 31536000);
  
  int i;
  for(i = 0; i < TRAVEL_LIMIT; i++){
    if(i % 10000000 == 0){
      printf("Current Year: %d | Travel Progress: %.2f%%\n", (localtime(&traveled_time)->tm_year + 1900), ((float)i / TRAVEL_LIMIT) * 100);
    }
    traveled_time--;
  }
  
  printf("\n\nArrival at destination time: %s\n", ctime(&traveled_time));
  
  return 0;
}