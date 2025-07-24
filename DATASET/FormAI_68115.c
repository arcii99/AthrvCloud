//FormAI DATASET v1.0 Category: Text processing ; Style: surprised
#include <stdio.h>
#include <string.h>

int main() {
  printf("Hey there! I am a text processing program. ");

  char sentence[1000];
  printf("What sentence would you like me to process?\n");
  fgets(sentence, 1000, stdin);

  printf("Wow, that's quite a sentence! Let's make it more interesting:\n");

  // Capitalize the first letter of each word
  for (int i = 0; sentence[i] != '\0'; i++) {
    if (i == 0 || sentence[i-1] == ' ') {
      if (sentence[i] >= 'a' && sentence[i] <= 'z') {
        sentence[i] -= 32;
      }
    }
  }
  printf("%s", sentence);

  // Count the number of vowels and consonants
  int vowels = 0, consonants = 0;
  for (int i = 0; sentence[i] != '\0'; i++) {
    if (sentence[i] >= 'a' && sentence[i] <= 'z' ||
        sentence[i] >= 'A' && sentence[i] <= 'Z') {
      switch (sentence[i]) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
          vowels++;
          break;
        default:
          consonants++;
          break;
      }
    }
  }
  printf("Did you know that your sentence has %d vowels and %d consonants?\n", vowels, consonants);

  // Replace every occurrence of "the" with "ze"
  char *word = strtok(sentence, " \n");
  while (word != NULL) {
    if (strcmp(word, "the") == 0) {
      printf("Ze ");
    } else {
      printf("%s ", word);
    }
    word = strtok(NULL, " \n");
  }

  // Reverse the sentence
  printf("\nOne more surprise coming up! Drum roll please...\n");
  for (int i = strlen(sentence) - 1; i >= 0; i--) {
    printf("%c", sentence[i]);
  }

  printf("\n\nThank you for using my text processing program!\n");

  return 0;
}