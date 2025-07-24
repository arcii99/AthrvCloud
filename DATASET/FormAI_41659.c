//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateConspiracy(char *conspiracy, char *plausible, char *ridiculous) {
  int randomNum = rand() % 3;
  switch (randomNum) {
    case 0:
      sprintf(conspiracy, "Did you know that all pigeons are actually government drones? %s", plausible);
      break;
    case 1:
      sprintf(conspiracy, "I heard that the moon landing was actually faked by the government. %s", ridiculous);
      break;
    case 2:
      sprintf(conspiracy, "I bet you didn't know that aliens are already among us and controlling everything. %s", plausible);
      break;
    default:
      sprintf(conspiracy, "I can't think of a conspiracy right now, sorry!");
      break;
  }
}

int main() {
  srand(time(NULL));
  char conspiracy[200];
  char plausible[50] = "It's just a theory, but who knows?";
  char ridiculous[50] = "Of course it's not true, but it's fun to think about!";
  for (int i = 0; i < 50; i++) {
    generateConspiracy(conspiracy, plausible, ridiculous);
    printf("%s\n\n", conspiracy);
  }
  return 0;
}