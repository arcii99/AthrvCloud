//FormAI DATASET v1.0 Category: Pattern printing ; Style: creative
#include <stdio.h>

int main() {
  int size;
  printf("Enter the size of the pattern: ");
  scanf("%d", &size);

  // Upper half of the pattern
  for(int i = 0; i < size; i++) {
    printf("* ");
    for(int j = 1; j < i; j++) {
      printf("%d ", i - j);
    }
    printf("\n");
  }

  // Lower half of the pattern
  for(int i = size - 2; i >= 0; i--) {
    printf("* ");
    for(int j = 1; j < i; j++) {
      printf("%d ", i - j);
    }
    printf("\n");
  }
  
  return 0;
}