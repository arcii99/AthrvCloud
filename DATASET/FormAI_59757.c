//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: curious
#include <stdio.h>

int main() {
  char text[100];
  printf("Enter some text: ");
  fgets(text, 100, stdin); // Inputs text from user

  printf("\n%s\n\n", text);

  int i, j;
  for (i = 0; text[i] != '\0'; i++) {
    for (j = 0; j < 8; j++) { // Divides each character into 8 segments
      if (text[i] & (1 << j)) {
        if (j % 2 == 0) {
          printf("*"); // Prints asterisk if the segment is 1
        } else {
          printf(" "); // Prints space if the segment is 0
        }
      } else {
        if (j % 2 == 0) {
          printf(" "); // Prints space if the segment is 0
        } else {
          printf("*"); // Prints asterisk if the segment is 1
        }
      }
    }
    printf("\n"); // New line for each character
  }

  return 0;
}