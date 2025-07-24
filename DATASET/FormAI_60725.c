//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  char* conspiracies[] = {
    "The government is secretly controlling the weather with chemtrails",
    "The moon landing was faked by Hollywood",
    "Aliens are real and the government is covering it up",
    "The Illuminati controls everything from the shadows",
    "The Earth is flat and NASA is lying to us",
    "9/11 was an inside job orchestrated by the government",
    "Vaccines are actually harmful and the government is covering it up",
    "The CIA assassinated JFK to keep him from uncovering their secrets",
    "The world is actually run by a secret cabal of reptilian humanoids"
  };

  srand(time(NULL));
  int index = rand() % 9;
  
  printf("Did you know that %s?\n", conspiracies[index]);
  printf("I know it may sound crazy, but just think about it for a moment...\n");
  printf("The truth is often stranger than fiction!\n");
  
  return 0;
}