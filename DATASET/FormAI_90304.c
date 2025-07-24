//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  char *conspiracy[] = {
    "The moon landing was faked.",
    "9/11 was an inside job.",
    "The government is controlling our minds through chemtrails.",
    "The earth is flat.",
    "Aliens are among us and the government is covering it up.",
    "The Illuminati controls everything.",
    "The vaccine industry is a scam to make money and control populations.",
    "The government is hiding evidence of time travel.",
    "The Bermuda Triangle is a portal to another dimension.",
    "The Titanic sinking was planned and not an accident."
  };
  
  int size = sizeof(conspiracy)/sizeof(int); //Calculate size of the array
  time_t t;
  srand((unsigned) time(&t)); //Seed random number generator
  
  printf("Random Conspiracy Theory Generator\n");
  printf("----------------------------\n");
  
  int i;
  for (i=0; i<5; i++) { //Generate 5 random conspiracy theories
    int r = rand() % size;
    printf("%d. %s\n", i+1, conspiracy[r]);
  }

  return 0;
}