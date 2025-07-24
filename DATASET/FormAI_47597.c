//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: peaceful
#include <stdio.h>

int main() {
  char input_char;
  int rows = 5, cols = 5;
  
  printf("Enter a character to convert to ASCII art: ");
  scanf("%c", &input_char);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if ((i == 0 && j == 0) || (i == rows - 1 && j == cols - 1)) {
        printf("  ");
      } else if ((i == 0 && j == cols - 1) || (i == rows - 1 && j == 0)) {
        printf("  ");
      } else if (i == j) {
        printf("%c ", input_char);
      } else if (i == 0 || i == rows - 1) {
        printf("%c ", input_char);
      } else if (j == 0 || j == cols - 1) {
        printf("%c ", input_char);
      } else {
        printf("  ");
      }
    }
    
    printf("\n");
  }

  return 0;
}