//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: imaginative
#include<stdio.h>
#include<string.h>

/* C Cat Language Translator */

int main() {
  char phrase[1000], translated[1000]; // Input phrase and translated phrase
  int length, i, j = 0; // Length of input phrase, iterator variables

  printf("Enter a sentence in C Cat Language: ");
  gets(phrase); // Reading input phrase

  length = strlen(phrase); // Calculating length of phrase

  for(i = 0; i < length; i++) { // Loop through each character
    if(phrase[i] == 'm') { // If character is 'm'
      translated[j++] = 'c'; // Replace 'm' with 'c'
    } else if(phrase[i] == 'e') { // If character is 'e'
      translated[j++] = 'a'; // Replace 'e' with 'a'
    } else if(phrase[i] == 'o') { // If character is 'o'
      translated[j++] = 't'; // Replace 'o' with 't'
    } else { // If character is anything else
      translated[j++] = phrase[i]; // Copy character as is
    }
  }

  translated[j] = '\0'; // Null terminate translated phrase
  printf("Translated sentence: %s\n", translated); // Print translated phrase

  return 0; // Return success
}