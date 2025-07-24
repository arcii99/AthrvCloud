//FormAI DATASET v1.0 Category: Text processing ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 100

int main() {
  char myString[MAX_STRING_LENGTH];
  int numVowels = 0, numConsonants = 0;

  printf("Enter a string: ");
  fgets(myString, MAX_STRING_LENGTH, stdin);

  // Remove newline character from the input
  myString[strcspn(myString, "\n")] = 0;

  // Convert all characters to lowercase for easier processing
  for(int i = 0; myString[i]; i++){
    myString[i] = tolower(myString[i]);
  }

  // Process the string to count vowels and consonants
  for(int i = 0; myString[i]; i++){
    if(myString[i] == 'a' || myString[i] == 'e' || myString[i] == 'i' || myString[i] == 'o' || myString[i] == 'u'){
      numVowels++;
    } else if(myString[i] >= 'a' && myString[i] <= 'z'){
      numConsonants++;
    }
  }

  // Print the results
  printf("The string entered is: %s\n", myString);
  printf("Number of vowels: %d\n", numVowels);
  printf("Number of consonants: %d\n", numConsonants);

  return 0;
}