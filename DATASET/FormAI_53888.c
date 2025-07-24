//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: Linus Torvalds
#include <stdio.h>

int main() {
  int size, i, j;
  
  printf("Enter the size of the ASCII art (minimum 5): ");
  scanf("%d", &size);
  
  if(size < 5) {
    printf("Invalid size!\n");
    return 1;
  }
  
  for(i = 0; i < size; i++) {
    for(j = 0; j < size; j++) {
      if(i == 0 || i == size - 1 || j == 0 || j == size - 1) {
        printf("#");
      } else if(i == j || i + j == size - 1) {
        printf("*");
      } else if(i == size / 2 || j == size / 2) {
        printf("$");
      } else {
        printf("-");
      }
    }
    printf("\n");
  }
  
  return 0;
}