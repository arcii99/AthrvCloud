//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: funny
#include <stdio.h>
#include <string.h>

int main() {
  char input[100];
  printf("Meow, welcome to the Cat Language Translator! Please enter your sentence: ");
  fgets(input, 100, stdin);
  
  char output[400];
  strcpy(output, "Meow, here is your translated sentence: ");
  
  for(int i=0; i<strlen(input); i++) {
    // Handle spaces
    if(input[i] == ' ') {
      strcat(output, " meow");
    }
    // Handle vowels
    else if(input[i] == 'a' || input[i] == 'e' || input[i] == 'i' || input[i] == 'o' || input[i] == 'u') {
      strcat(output, "me");
    }
    // Handle consonants
    else {
      strcat(output, "ow");
    }
  }
  
  printf("%s\n", output);
  printf("Meow, wasn't that fun? Want to translate another sentence? Meow-surely!\n");
  return 0;
}