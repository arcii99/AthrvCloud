//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
  srand(time(NULL));

  char* fortunes[] = {
    "Darkness looms beyond your door",
    "The crows will be your guide",
    "A great danger approaches",
    "Your past will catch up with you",
    "You will meet someone special soon",
    "Chaos reigns in your future",
    "The stars are not in your favor",
    "A close friend will betray you",
    "Your greatest fear will become reality",
    "Your luck will turn against you"
  };

  int fortuneIndex = rand() % 10;

  printf("Welcome to the Automated Fortune Teller\n\n");
  printf("Please think of a yes or no question and hit enter to reveal your fate...\n\n");
  
  char question[100];
  scanf("%[^\n]%*c", question);

  int numChars = strlen(question);
  int numVowels = 0;

  // Count the number of vowels in the question
  for (int i = 0; i < numChars; i++) {
    char currentChar = tolower(question[i]);
    if (currentChar == 'a' || currentChar == 'e' || currentChar == 'i' || currentChar == 'o' || currentChar == 'u') {
      numVowels++;
    }
  }

  // Determine if the fortune will be good or bad based on number of vowels
  if (numVowels % 2 == 0) {
    printf("\nYour fate is sealed.\n\n");
    printf("Your fortune: %s\n", fortunes[fortuneIndex]);
    printf("Remember, destiny is a fickle thing, so heed this warning well...\n");
  } else {
    printf("\nYour fate is uncertain.\n\n");
    printf("The spirits are unclear, ask again later...\n");
  }

  return 0;
}