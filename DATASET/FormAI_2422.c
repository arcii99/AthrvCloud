//FormAI DATASET v1.0 Category: Spam Detection System ; Style: Donald Knuth
#include <stdio.h>
#include <string.h>

int main() {
  char spamWords[5][10] = { "viagra", "free", "lottery", "money", "cash" };
  char message[100];
  int numWords = 0;

  printf("Enter your message: ");
  fgets(message, 100, stdin); // get user input

  char* word = strtok(message, " "); // tokenize message by space
  
  while (word != NULL) {
    for (int i = 0; i < 5; i++) {
      if (strcasecmp(word, spamWords[i]) == 0) { // case-insensitive spam word match
        numWords++;
      }
    }
    word = strtok(NULL, " ");
  }
  
  if (numWords > 0) {
    printf("The message contains %d spam word(s). Please revise and try again.\n", numWords);
  } else {
    printf("The message passes our spam detection system. Thank you!\n");
  }

  return 0;
}