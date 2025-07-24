//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(0)); // set the seed for the random number generator
  
  // generate random conspiracy theories
  char* conspiracyTheory[] = {
    "The government is secretly controlling the weather",
    "The moon landing was faked by NASA",
    "Aliens have been living among us for years",
    "The Illuminati is controlling all world events",
    "Chemtrails are poisoning our air and water",
    "The earth is really flat, and the governments are lying to us",
    "The world will end in 2021",
    "The COVID-19 vaccine is actually a microchip tracking device",
    "The Bermuda Triangle is a portal to another dimension",
    "The Loch Ness Monster is real and the government is hiding it from us"
  };
  
  // select and print a random conspiracy theory
  int index = rand() % 10;
  printf("Did you know: %s\n", conspiracyTheory[index]);
  
  return 0;
}