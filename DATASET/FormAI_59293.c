//FormAI DATASET v1.0 Category: Pattern printing ; Style: Ken Thompson
#include <stdio.h>

int main() {
  int height, width, mid, i, j;

  printf("Enter the height of the pattern: ");
  scanf("%d", &height);
  width = (height + 1) / 2;  // Calculate width based on height

  for (i = 1; i <= height; i++) {
    mid = i <= width ? i : height - i + 1;  // Calculate mid for each row
    for (j = 1; j <= mid; j++)
      printf("*");
    printf("\n");  // Move to new line

    if (i == width)  // Skip the middle row
      continue;

    // Print the second half of the row
    for (j = 1; j <= width - mid; j++)
      printf(" ");
    printf("*");
    for (j = 1; j <= width - mid - 1; j++)
      printf(" ");
    printf("\n");  // Move to new line
  }

  return 0;
}