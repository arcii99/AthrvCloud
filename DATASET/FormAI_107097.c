//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int seed = time(NULL); // seed for random number generator
  srand(seed); // initialize random number generator

  char *subjects[] = {
    "The government",
    "Aliens",
    "The Illuminati",
    "The deep state",
    "The Freemasons",
    "The reptilian race"
  };

  char *verbs[] = {
    "is controlling",
    "is manipulating",
    "is hiding",
    "is funding",
    "is brainwashing",
    "is sabotaging"
  };

  char *objects[] = {
    "the media",
    "the weather",
    "the stock market",
    "the education system",
    "the internet",
    "our dreams"
  };

  char *evidence[] = {
    "There are secret documents that prove it",
    "It's obvious if you read between the lines",
    "Whistleblowers have come forward",
    "There are too many coincidences",
    "The truth is being suppressed",
    "The internet is censoring the truth"
  };

  char *actions[] = {
    "We need to wake up and resist",
    "We need to spread the word",
    "We need to prepare for the worst",
    "We need to band together and fight back",
    "We need to take to the streets",
    "We need to pray for salvation"
  };

  int num_subjects = sizeof(subjects) / sizeof(char *);
  int num_verbs = sizeof(verbs) / sizeof(char *);
  int num_objects = sizeof(objects) / sizeof(char *);
  int num_evidence = sizeof(evidence) / sizeof(char *);
  int num_actions = sizeof(actions) / sizeof(char *);

  printf("Random Conspiracy Theory Generator\n");
  printf("---------------------------------\n\n");
  printf("Theory: %s %s %s because %s. %s\n", 
          subjects[rand() % num_subjects], 
          verbs[rand() % num_verbs], 
          objects[rand() % num_objects], 
          evidence[rand() % num_evidence], 
          actions[rand() % num_actions]);
  
  return 0;
}