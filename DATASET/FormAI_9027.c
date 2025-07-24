//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL)); // initialize random seed
  
  // list of conspiracy theories
  char *theories[] = {"Aliens built the pyramids", 
                      "The moon landing was faked", 
                      "The government controls the weather", 
                      "Chemtrails are poisoning us", 
                      "COVID-19 is a conspiracy to control the population", 
                      "The Illuminati controls everything"};
  
  // generate a random conspiracy theory
  int index = rand() % 6;
  char *theory = theories[index];
  
  // print the theory
  printf("Here's a conspiracy theory for you:\n");
  printf("%s\n", theory);
  
  return 0;
}