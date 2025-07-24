//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  srand(time(NULL)); //seed for randomization
  char* nouns[] = {"government", "aliens", "Illuminati", "New World Order", "Masons", "deep state", "Big Pharma", "elite", "globalists", "Black Ops", "CIA", "FBI", "NSA", "CDC", "World Health Organization", "Freemasons", "The Vatican", "the Rothschilds", "the Rockefellers", "the Bilderbergs"};
  char* verbs[] = {"manipulate", "control", "brainwash", "infiltrate", "dominate", "conspire", "plot", "cover up", "suppress", "silence", "experiment on", "deceive", "harvest", "enslave", "eliminate", "expose"};
  char* adjectives[] = {"secret", "sinister", "evil", "unholy", "deceptive", "all-seeing", "powerful", "destructive", "malevolent", "corrupt", "maniacal", "mad", "nefarious", "covert", "global", "hidden"};
  char* objects[] = {"people", "the environment", "food supply", "media", "society", "technology", "the weather", "religion", "history", "the economy", "education system", "political system", "the military", "masses", "vaccines", "minerals", "disease", "natural disasters"};

  printf("Welcome to the Random Conspiracy Theory Generator!\n");

  while(1) {
    printf("Here's a conspiracy theory for you:\n");
    printf("The %s %s is trying to %s the %s!\n", adjectives[rand() % 16], nouns[rand() % 20], verbs[rand() % 16], objects[rand() % 18]);
    printf("What do you think? Believable or not? (y/n)\n");

    char input;
    scanf(" %c", &input);

    if (input == 'n') {
      printf("You're probably right... this time.\n");
    } else {
      printf("Ha! I knew it.\n");
    }
  }
  return 0;
}