//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL)); // seed random number generator

  const char* subjects[] = {
    "The government",
    "The Illuminati",
    "Aliens",
    "Big Pharma",
    "The Rothschilds",
    "The Reptilians",
    "The Deep State",
    "The Freemasons",
    "The New World Order",
    "The Bilderberg Group",
    "The Trilateral Commission",
    "The Council on Foreign Relations",
    "The Vatican",
    "The Military-Industrial Complex",
    "The Globalists",
    "The Antichrist"
  }; // list of possible subjects for the conspiracy theory

  const char* verbs[] = {
    "is controlling",
    "is manipulating",
    "is brainwashing",
    "is poisoning",
    "is surveilling",
    "is censoring",
    "is suppressing",
    "is infiltrating",
    "is creating",
    "is funding",
    "is planning",
    "is engineering",
    "is spreading",
    "is covering up",
    "is promoting",
    "is hiding"
  }; // list of possible verbs for the conspiracy theory

  const char* objects[] = {
    "the media",
    "the economy",
    "the weather",
    "the education system",
    "the food supply",
    "the justice system",
    "the health industry",
    "the entertainment industry",
    "the political system",
    "the technology industry",
    "the energy industry",
    "the environment",
    "human genetics",
    "the moon landing",
    "9/11"
  }; // list of possible objects for the conspiracy theory

  const char* endings[] = {
    "to enslave humanity",
    "to depopulate the world",
    "to establish a one-world government",
    "to turn us all into mindless slaves",
    "to create a new world order",
    "to bring about the end times",
    "to usher in the Antichrist",
    "to terraform the earth for their own use"
  }; // list of possible endings for the conspiracy theory

  int subject_index = rand() % 16;
  int verb_index = rand() % 16;
  int object_index = rand() % 15;
  int ending_index = rand() % 8;

  printf("%s %s %s %s.\n", subjects[subject_index], verbs[verb_index], objects[object_index], endings[ending_index]);

  return 0;
}