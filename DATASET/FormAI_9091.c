//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: romantic
#include <stdio.h>
#include <string.h>

int main() {
  char message[100];
  int love_count = 0, hate_count = 0, i;

  printf("Enter your message:\n");
  scanf("%100[^\n]", message);

  for (i = 0; i < strlen(message); i++) {
    if (message[i] == 'l' || message[i] == 'o' || message[i] == 'v' || message[i] == 'e') {
      love_count++;
    }
    else if (message[i] == 'h' || message[i] == 'a' || message[i] == 't' || message[i] == 'e') {
      hate_count++;
    }
  }

  if (love_count > hate_count) {
    printf("\nIt's clear that you are deeply in love! Congrats!\n");
    printf("Here's some code to express your feelings:\n\n");
    printf("int main() {\n  printf(\"I love you more than code.\");\n  return 0;\n}\n");
  }
  else if (hate_count > love_count) {
    printf("\nIt seems like things aren't going so well. Sorry to hear that.\n");
    printf("Here's some code to help you get over it:\n\n");
    printf("int main() {\n  printf(\"Programming is my new love.\");\n  return 0;\n}\n");
  }
  else {
    printf("\nHmm, it's hard to tell what you're feeling. Maybe you should be more clear in your message!\n");
    printf("Here's some code to help with that:\n\n");
    printf("int main() {\n  printf(\"Please tell me if you love or hate me.\");\n  return 0;\n}\n");
  }

  return 0;
}