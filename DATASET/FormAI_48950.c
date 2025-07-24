//FormAI DATASET v1.0 Category: Pattern printing ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

int main() {
  int size, i, j, count = 1, temp;

  printf("Enter the size of the pattern: ");
  scanf("%d", &size);

  // Use temporary variable to swap value
  temp = size;

  // Outer loop for rows
  for (i = 1; i <= size; i++) {
    // Inner loop for columns
    for (j = 1; j <= size; j++) {
      if (j <= i) {
        printf("%d ", count);
        count++;
      } else {
        printf("%d ", temp);
        temp--;
      }
    }
    // Move to new line after a row finishes
    printf("\n");

    // Reset count and temp
    count = i + 1;
    temp = size - i;
  }
  return 0;
}