//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // Define the fortune messages
  char fortunes[5][100] = {
      "You will find great success in all your endeavors.",
      "Today is a day of creativity and inspiration.",
      "Your future looks bright, keep working hard.",
      "You will soon meet the love of your life.",
      "A great opportunity is coming your way, be ready to seize it."
  };

  // Set a seed for the random number generator
  srand(time(0));

  // Generate a random number between 0 and 4
  int random_number = rand() % 5;

  // Print the fortune message
  printf("Your fortune for today: %s\n", fortunes[random_number]);

  return 0;
}