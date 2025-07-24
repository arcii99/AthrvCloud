//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  char* topics[] = {"Chemtrails", "Illuminati", "Flat Earth", "Moon Landing Hoax", "Reptilian Elite", "9/11 Inside Job"};
  char* verbs[] = {"are controlling", "are manipulating", "are hiding the truth about", "are covering up", "are brainwashing people about", "are altering the course of", "are conspiring to destroy", "are planning to takeover"};
  char* objects[] = {"the government", "the media", "the education system", "our minds", "the weather", "our health", "the economy", "our technology", "our future", "our past"};

  srand(time(0));

  for(int i = 0; i < 10; i++) {
    int t_index = rand() % 6; // Get a random index for the topic array
    int v_index = rand() % 8; // Get a random index for the verb array
    int o_index = rand() % 10; // Get a random index for the object array

    // Print out the conspiracy theory sentence
    printf("%d. %s %s %s.\n", i+1, topics[t_index], verbs[v_index], objects[o_index]);
  }

  return 0;
}