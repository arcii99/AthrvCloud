//FormAI DATASET v1.0 Category: Game ; Style: introspective
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int main(void) {

  char sentence[100];
  int vowels=0, consonants=0, digits=0, spaces=0, symbols=0, i=0;

  printf("Please enter a sentence: ");
  
  fgets(sentence, 100, stdin);

  while(sentence[i] != '\0') {

    if(isalpha(sentence[i])) {

      sentence[i] = tolower(sentence[i]);

      if(sentence[i] == 'a' || sentence[i] == 'e' || sentence[i] == 'i' || sentence[i] == 'o' || sentence[i] =='u') {
        vowels++;
      } else {
        consonants++;
      }
    } else if(isdigit(sentence[i])) {
      digits++;
    } else if(isspace(sentence[i])) {
      spaces++;
    } else {
      symbols++;
    }

    i++;
  }

  printf("\n------------\n");
  printf("ANALYSIS:\n");
  printf("------------\n");
  printf("Vowels: %d\n", vowels);
  printf("Consonants: %d\n", consonants);
  printf("Digits: %d\n", digits);
  printf("Spaces: %d\n", spaces);
  printf("Symbols: %d\n", symbols);

  return 0;
}