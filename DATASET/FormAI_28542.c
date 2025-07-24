//FormAI DATASET v1.0 Category: Spam Detection System ; Style: mathematical
#include <stdio.h>
#include <string.h>

int main() {
  char message[1000];
  int spam = 0;

  printf("Enter your message:\n");
  fgets(message, 1000, stdin);

  // Count the number of exclamation marks
  int num_exclamation_marks = 0;
  for (int i=0; i<strlen(message); i++) {
    if (message[i] == '!') {
      num_exclamation_marks++;
    }
  }

  // If there are more than 5 exclamation marks, it's probably spam
  if (num_exclamation_marks > 5) {
    spam = 1;
  }

  // Count the number of dollar signs
  int num_dollar_signs = 0;
  for (int i=0; i<strlen(message); i++) {
    if (message[i] == '$') {
      num_dollar_signs++;
    }
  }

  // If there are more than 3 dollar signs, it's probably spam
  if (num_dollar_signs > 3) {
    spam = 1;
  }

  // Display the result
  if (spam) {
    printf("This message is likely spam.\n");
  } else {
    printf("This message is not spam.\n");
  }

  return 0;
}