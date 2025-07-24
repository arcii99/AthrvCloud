//FormAI DATASET v1.0 Category: Pattern printing ; Style: Romeo and Juliet
#include <stdio.h>

// Romeo, oh Romeo, wherefore art thou Romeo?
int main() {
  int rows;
  printf("Oh, Juliet my dear, please tell me how many rows to print: ");
  scanf("%d", &rows);

  // Shall I compare thee to a summer's day?
  for (int i = 0; i < rows; i++) {
    // A rose by any other name would smell as sweet.
    for (int j = 0; j < i + 1; j++) {
      printf("*");
    }
    printf("\n");
  }

  // Good night, good night! Parting is such sweet sorrow
  for (int k = rows - 1; k >= 0; k--) {
    for (int m = 0; m < k; m++) {
      printf(" ");
    }
    for (int n = k; n < rows; n++) {
      printf("*");
    }
    printf("\n");
  }

  // But, soft! what light through yonder window breaks?
  return 0;
}