//FormAI DATASET v1.0 Category: DOS detector ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  char buffer[100];
  int count = 0;
  printf("Enter a string: ");
  fgets(buffer, 100, stdin);

  for (int i = 0; i < strlen(buffer); i++) {
    if (buffer[i] == 'C' || buffer[i] == 'c') {
      count++;
    }
  }

  if (count >= 2 && buffer[0] == 'D' && buffer[1] == 'O' && buffer[2] == 'S') {
    printf("The string entered is a valid C DOS detector.");
  } else {
    printf("The string entered is not a valid C DOS detector.");
  }

  return 0;
}