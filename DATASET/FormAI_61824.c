//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  char *conspiracy[10] = {"The moon landing was faked",
                           "The earth is actually flat",
                           "The government is run by lizard people",
                           "Chemtrails are controlling our minds",
                           "The Illuminati control everything",
                           "9/11 was an inside job",
                           "The Holocaust never happened",
                           "COVID-19 is a bio-weapon created by the government",
                           "The Bermuda Triangle is a portal to another dimension",
                           "The Denver airport is hiding underground bunkers for the wealthy elite"};

  srand(time(NULL)); //seeding random number generator with current time

  int random_index = rand() % 10; //generating a random integer between 0 and 9

  printf("You want to know the truth? %s\n", conspiracy[random_index]);

  return 0;
}