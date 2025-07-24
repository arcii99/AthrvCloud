//FormAI DATASET v1.0 Category: Text processing ; Style: authentic
#include <stdio.h>
#include <ctype.h>

int main() {
  char sentence[100];
  int i, upperCount = 0, lowerCount = 0, digitCount = 0, punctuationCount = 0;

  printf("Enter a sentence: ");
  fgets(sentence, 100, stdin);

  for(i=0; sentence[i] != '\0'; i++) {
    if(isupper(sentence[i])) {
      upperCount++;
    }
    else if(islower(sentence[i])) {
      lowerCount++;
    }
    else if(isdigit(sentence[i])) {
      digitCount++;
    }
    else if(ispunct(sentence[i])) {
      punctuationCount++;
    }
  }

  printf("\n");
  printf("************ Text Processing Report ************\n\n");
  printf("The sentence you entered is: %s", sentence);
  printf("Number of uppercase letters: %d\n", upperCount);
  printf("Number of lowercase letters: %d\n", lowerCount);
  printf("Number of digits: %d\n", digitCount);
  printf("Number of punctuation characters: %d\n", punctuationCount);

  return 0;
}