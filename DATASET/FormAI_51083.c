//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: high level of detail
#include <stdio.h>

int main() {
  char user_input[100];
  printf("Welcome to the C Cat Language Translator!\n");
  printf("Please enter a phrase in C Cat Language: ");
  fgets(user_input, sizeof(user_input), stdin);

  // Replacing 'c' with 'meow'
  for (int i = 0; user_input[i] != '\0'; ++i) {
    if (user_input[i] == 'c') {
      user_input[i] = 'm';
      printf("meow");
    } else {
      printf("%c", user_input[i]);
    }
  }

  return 0;
}