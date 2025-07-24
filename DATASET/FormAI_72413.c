//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: surprised
#include <stdio.h>
#include <string.h>

int main() {
  char sentence[1000], translated[1000];
  int i, j;

  printf("Enter a sentence in C Alien Language: ");
  fgets(sentence, 1000, stdin);

  // loop through each character in the sentence
  for (i = 0; i < strlen(sentence); i++) {
    // check if the current character is a consonant or vowel
    if ((sentence[i] == 'C') || (sentence[i] == 'c') ||
        (sentence[i] == 'Q') || (sentence[i] == 'q') ||
        (sentence[i] == 'T') || (sentence[i] == 't') ||
        (sentence[i] == 'X') || (sentence[i] == 'x')) {
      // change the consonant to a 'G'
      translated[j] = 'G';
    } else if ((sentence[i] == 'A') || (sentence[i] == 'a') ||
               (sentence[i] == 'E') || (sentence[i] == 'e') ||
               (sentence[i] == 'I') || (sentence[i] == 'i') ||
               (sentence[i] == 'O') || (sentence[i] == 'o') ||
               (sentence[i] == 'U') || (sentence[i] == 'u')) {
      // change the vowel to an 'L'
      translated[j] = 'L';
    } else {
      // leave any other character as is
      translated[j] = sentence[i];
    }
    j++;
  }

  // print out the translated sentence
  printf("\nTranslated sentence: %s\n", translated);

  return 0;
}