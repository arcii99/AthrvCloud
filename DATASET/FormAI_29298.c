//FormAI DATASET v1.0 Category: Weather simulation ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL)); //initialize random seed
  
  int temperature = rand() % 100; //generate a random temperature between 0-99
  int humidity = rand() % 100; //generate a random humidity between 0-99
  int rain_chance = rand() % 100; //generate a random chance of rain between 0-99
  
  printf("Welcome to the wacky weather simulator!\n");
  printf("Today's temperature is %d degrees Fahrenheit\n", temperature);
  
  if (temperature > 80) {
    printf("It's a scorcher out there! Wear sunscreen and stay hydrated!\n");
  } else if (temperature > 60) {
    printf("It's a pleasant day for a stroll. Enjoy the fresh air!\n");
  } else {
    printf("Bundle up! It's chilly outside.\n");
  }
  
  printf("The humidity is %d percent\n", humidity);
  
  if (humidity > 70) {
    printf("It's muggy outside. You might want to bring a towel.\n");
  } else if (humidity > 40) {
    printf("The air is comfortable today. No need to fret about sweating.\n");
  } else {
    printf("You might want to apply some lotion, it's dry outside!\n");
  }
  
  if (rain_chance > 50) {
    printf("There's a good chance of rain today. Don't forget your umbrella!\n");
  } else {
    printf("Looks like it's going to be a dry day. Time to relax and enjoy the sunshine!\n");
  }
  
  return 0;
}