//FormAI DATASET v1.0 Category: Weather simulation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL));

  printf("Welcome to the surrealist weather simulation program!\n");

  while (1) {
    int temp = rand() % 100;
    int rain_chance = rand() % 100;

    printf("Today's temperature is %d degrees.\n", temp);

    if (temp < 5) {
      printf("It's freezing outside, I suggest you wear a coat made of fire.\n");
    }
    else if (temp < 20) {
      printf("It's a bit chilly, but nothing a sweater made of clouds can't handle.\n");
    }
    else if (temp < 30) {
      printf("It's a beautiful day outside! I heard the birds are wearing bowties today.\n");
    }
    else if (temp < 50) {
      printf("It's getting pretty hot out there! I suggest you take a dip in the chocolate river.\n");
    }
    else {
      printf("The heat is unbearable! It's time for the sun to take a chill pill.\n");
    }

    if (rain_chance < 10) {
      printf("Looks like rain is in the forecast, better bring a paper umbrella today.\n");
    }
    else {
      printf("The skies are clear today, you could probably see through time itself.\n");
    }

    printf("\n");

    // Wait for user to press any key before continuing
    system("pause");
  }

  return 0;
}