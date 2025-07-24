//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: high level of detail
#include <stdio.h>
#include <string.h>

void meow_to_text(char* input) {
  if (strcmp(input, "meow") == 0) printf("Hello\n");
  else if (strcmp(input, "meow meow") == 0) printf("How are you?\n");
  else if (strcmp(input, "meow meow meow") == 0) printf("I'm good, thanks\n");
  else if (strcmp(input, "meow meow meow meow") == 0) printf("Goodbye\n");
  else printf("I'm sorry, I don't understand that meow\n");
}

int main() {
  char input[30];
  printf("Welcome to the C Cat Language Translator\n");
  printf("Please enter your meows: ");
  fgets(input, 30, stdin);
  input[strcspn(input, "\n")] = 0; // remove newline character from input
  meow_to_text(input);
  return 0;
}