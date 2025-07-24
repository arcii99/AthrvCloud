//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: mathematical
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/* Function to convert C Cat Language to English */
void cCatToEnglish(char* inputString) {
  char* token;
  char* delimiter = " ";

  token = strtok(inputString, delimiter);

  while(token != NULL) {
    if(strcmp(token, "meow") == 0) {
      printf("H\n");
    } else if(strcmp(token, "purr") == 0) {
      printf("e\n");
    } else if(strcmp(token, "hiss") == 0) {
      printf("l\n");
    } else if(strcmp(token, "growl") == 0) {
      printf("o\n");
    } else {
      printf("%s", token);
    }

    token = strtok(NULL, delimiter);
  }
}

/* Main function */
int main() {
  char cCatString[] = "meow purr growl hiss";
 
  printf("C Cat Language: %s\n", cCatString);
  printf("English Translation: ");
  cCatToEnglish(cCatString);

  return 0;
}