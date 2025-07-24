//FormAI DATASET v1.0 Category: Recursive ; Style: Cyberpunk
#include <stdio.h>

// Cyberpunk recursive function
void cyrec(int x) {
  if(x > 0) {
    printf("%d ", x);
    cyrec(x-1);
  } else if(x == 0) {
    printf("Activate the Grid!\n");
  } else {
    printf("Error: Grid overload!\n");
  }
}

int main() {
  int n;
  printf("Enter a positive integer for Grid activation: ");
  scanf("%d", &n);
  cyrec(n);
  return 0;
}