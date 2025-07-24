//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  // Welcome message to the user
  printf("Hello! I am your C RAM usage monitor!\n");

  // Random variable declarations
  int ram_usage = 0, min_usage = 0, max_usage = 100, time = 1;

  // Loop that runs for a minute
  while (time <= 60) {

    // Randomize RAM usage for every second
    ram_usage = rand() % (max_usage - min_usage + 1) + min_usage;

    // Display RAM usage
    printf("RAM usage: %d%%\n", ram_usage);

    // Sleep for a second to avoid overwhelming the system
    sleep(1);

    // If RAM usage is above 90%, scare the user
    if (ram_usage > 90) {
      printf("Warning! RAM usage above 90%%! Do not panic!...yet.\n");
    }

    // If RAM usage is less than 10%, make fun of the user
    if (ram_usage < 10) {
      printf("Ha! I bet your computer thinks it's pretty smart right now, using less than 10%% RAM. Well, we'll see who's laughing when you try to run 10 Chrome tabs at once.\n");
    }

    // Increment time counter
    time++;
  }

  // Farewell message to the user
  printf("Thanks for using the C RAM usage monitor! Have a great day!\n");

  // Exit program
  return 0;
}