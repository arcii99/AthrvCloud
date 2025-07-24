//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: Dennis Ritchie
#include <stdio.h>

int main() {
  int height, width;
  printf("Enter the height of the ASCII art: ");
  scanf("%d", &height);
  printf("Enter the width of the ASCII art: ");
  scanf("%d", &width);
  printf("\n");

  char ascii_chars[10] = {'#', '%', '$', '&', '@', '!', '*', '+', '-', '='};
  // Array of ASCII characters for design

  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      int index = (i + j) % 10; 
      putchar(ascii_chars[index]);
      // Print one of the ASCII characters from the array.
    }
    putchar('\n');
  }
  return 0;
}