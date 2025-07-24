//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: romantic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* This program translates English phrases into "cat speak" using C Cat Language (CCL) as a guide */

char* to_ccl(char* phrase) {
  char *ccl;

  // allocate memory for ccl string
  ccl = (char*) malloc(strlen(phrase) * sizeof(char));

  // loop through phrase and translate to ccl
  for (int i = 0; i < strlen(phrase); i++) {
    if (phrase[i] == 'h' || phrase[i] == 'h') {
      strcat(ccl, "m");
    } else if (phrase[i] == 'l' || phrase[i] == 'L') {
      strcat(ccl, "p");
    } else if (phrase[i] == 'o' || phrase[i] == 'O') {
      strcat(ccl, "t");
    } else {
      strcat(ccl, "k");
    }
  }
  return ccl;
}

int main() {
  char english_phrase[100];
  char *ccl_phrase;

  // prompt user for input
  printf("Please enter an English phrase: ");
  scanf("%[^\n]s", english_phrase);

  // translate phrase to ccl
  ccl_phrase = to_ccl(english_phrase);

  // print out translated phrase
  printf("In C Cat Language, that would be: %s\n", ccl_phrase);

  // free up memory allocated for ccl_phrase
  free(ccl_phrase);

  return 0;
}