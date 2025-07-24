//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: cheerful
#include<stdio.h>

int main() {
  char catTalk[50];

  printf("Welcome to C Cat Language Translator!\n");
  printf("Enter your meow: ");
  scanf("%s", catTalk);

  if (strcmp(catTalk, "meow") == 0) {
    printf("Translation: Hello, how are you?\n");
  } else if (strcmp(catTalk, "purr") == 0) {
    printf("Translation: I'm feeling content.\n");
  } else if (strcmp(catTalk, "hiss") == 0) {
    printf("Translation: Stay away from me!\n");
  } else {
    printf("Translation: I don't understand what you're saying. Please try again.\n");
  }

  return 0;
}