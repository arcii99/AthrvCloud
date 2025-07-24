//FormAI DATASET v1.0 Category: Funny ; Style: cheerful
#include <stdio.h>
#include <string.h>

int main() {
  char *message = "Hello, world!";

  int length = strlen(message);
  int i, j;

  for (i = 0; i <= length; i++) {
    for (j = 0; j < i; j++) {
      printf("%c", message[j]);
    }

    printf("\n");
  }

  return 0;
}