//FormAI DATASET v1.0 Category: Text processing ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>

int main() {
  char clue[100];
  int length;
  int i;

  printf("Ah, Watson, what do we have here? A clue, you say?\n");
  printf("What did you find at the crime scene?\n");
  fgets(clue, sizeof(clue), stdin);
  length = strlen(clue);

  printf("Let me take a closer look at this...\n");

  // Looping through each character of the clue
  for (i = 0; i < length; i++) {
    // Checking if the character is a letter
    if (isalpha(clue[i])) {

      // Converting upper case to lower case
      if (isupper(clue[i])) {
        clue[i] = tolower(clue[i]);
      }

      // Running analysis on the word "murder"
      if (i < length - 5 && clue[i] == 'm' && clue[i+1] == 'u' && clue[i+2] == 'r' && clue[i+3] == 'd' && clue[i+4] == 'e' && clue[i+5] == 'r') {
        printf("Interesting, the word 'murder' appears in this clue.\n");
      }

      // Running analysis on the word "blood"
      if (i < length - 4 && clue[i] == 'b' && clue[i+1] == 'l' && clue[i+2] == 'o' && clue[i+3] == 'o' && clue[i+4] == 'd') {
        printf("Curious, the word 'blood' appears in this clue.\n");
      }

      // Running analysis on the word "knife"
      if (i < length - 4 && clue[i] == 'k' && clue[i+1] == 'n' && clue[i+2] == 'i' && clue[i+3] == 'f' && clue[i+4] == 'e') {
        printf("Hmmm, the word 'knife' appears in this clue.\n");
      }
    }
  }

  printf("Good work, Watson. This clue will be useful in solving the case.\n");

  return 0;
}