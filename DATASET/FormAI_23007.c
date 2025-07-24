//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL));

  // Conspiracy subjects
  char *subjects[] = {"the government", "the Illuminati", "aliens", "Big Pharma", "the New World Order"};

  // Conspiracy verbs
  char *verbs[] = {"controls", "manipulates", "brainwashes", "suppresses", "influences"};

  // Conspiracy objects
  char *objects[] = {"the media", "the economy", "our thoughts", "the weather", "our elections"};

  // Conspiracy evidences
  char *evidences[] = {"chemtrails", "mind control experiments", "secret societies", "UFO sightings", "coverups"};

  char conspiracy[100];
  for(int i = 0; i < 10; i++) {
    int sIndex = rand() % 5;
    int vIndex = rand() % 5;
    int oIndex = rand() % 5;
    int eIndex = rand() % 5;

    // Sometimes, the conspiracy takes a different form
    if (rand() % 10 == 0) {
      sprintf(conspiracy, "%s is actually %s %s %s", subjects[sIndex], subjects[rand() % 5], verbs[rand() % 5], objects[rand() % 5]);
    } else {
      sprintf(conspiracy, "%s %s %s using %s", subjects[sIndex], verbs[vIndex], objects[oIndex], evidences[eIndex]);
    }

    printf("%s.\n", conspiracy);
  }

  return 0;
}