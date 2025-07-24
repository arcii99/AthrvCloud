//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  srand(time(NULL)); // initialize random seed

  // conspiracy theories
  char* theories[10] = {"The moon landing was faked", "Chemtrails are used for mind control", "The government is hiding evidence of aliens", "The Illuminati control world events", "The Earth is flat", "Vaccines cause autism", "9/11 was an inside job", "The New World Order is taking over", "The Rothschilds own everything", "The lizard people are real"};

  // locations
  char* locations[5] = {"Washington D.C.", "Area 51", "The Bermuda Triangle", "The Vatican", "Antarctica"};

  // people
  char* people[7] = {"The President", "The Queen of England", "Tom Cruise", "Bill Gates", "Elon Musk", "Mark Zuckerberg", "Jay-Z"};

  // generate random conspiracy theory
  int theory_index = rand() % 10;
  char* theory = theories[theory_index];

  // generate random location
  int location_index = rand() % 5;
  char* location = locations[location_index];

  // generate random person
  int person_index = rand() % 7;
  char* person = people[person_index];

  // print out the conspiracy theory
  printf("Did you know that %s is hiding evidence of %s in %s?\n", person, theory, location);

  return 0;
}