//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // set seed for random number generator
  srand(time(NULL));

  // create array of fortunes
  char *fortunes[] = {
    "A great adventure awaits you!",
    "You will find true love soon.",
    "Good news is on the way!",
    "Your hard work will pay off.",
    "A long lost friend will contact you.",
    "Travel is in your future.",
    "Opportunities are coming your way.",
    "Your wishes will come true.",
    "You will experience great happiness.",
    "Your life will be filled with abundance."
  };

  // get user's name
  char name[20];
  printf("Welcome to the automated fortune teller. What is your name?\n");
  scanf("%s", name);
  printf("Hello, %s. Let me tell your fortune.\n", name);

  // generate random index for fortune array and print fortune
  int index = rand() % 10;
  printf("Your fortune for today is: %s\n", fortunes[index]);

  return 0;
}