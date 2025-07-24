//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(0));
  char *people[] = {"government officials", "the Illuminati", "aliens", "Big Pharma", "the lizard people", "the Freemasons", "the New World Order"};
  char *events[] = {"9/11", "the moon landing", "the assassination of JFK", "the COVID-19 pandemic", "the Denver Airport"};
  char *effects[] = {"mind control", "chemtrails", "population control", "transhumanism", "the destruction of traditional values"};
  char *conspiracy = (char*) malloc(sizeof(char)*256);
  
  int rand_num_people = rand() % 7;
  int rand_num_events = rand() % 5;
  int rand_num_effects = rand() % 5;
  
  sprintf(conspiracy, "Did you know that %s are behind %s, in order to bring about %s?", people[rand_num_people], events[rand_num_events], effects[rand_num_effects]);
  
  printf("%s\n", conspiracy);
  
  free(conspiracy);
  
  return 0;
}