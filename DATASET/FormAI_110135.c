//FormAI DATASET v1.0 Category: Pattern printing ; Style: scientific
#include <stdio.h>

int main() {
  int rows, i, j, k, l, num = 1;
  printf("Enter the number of rows for the pattern: ");
  scanf("%d", &rows);
  for (i = 1; i <= rows; i++) {
    for (j = rows; j > i; j--) {
      printf(" ");
    }
    for (k = 1; k <= i; k++) {
      printf("%d", num);
      num++;
      if (num == 10) { /* Reset the number after reaching 9 */
        num = 1;
      }
    }
    for (l = i - 1; l >= 1; l--) {
      printf("%d", num);
      num++;
      if (num == 10) { /* Reset the number after reaching 9 */
        num = 1;
      }
    }
    printf("\n"); /* Print newline character */
  }
  return 0;
}