//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: surrealist
#include <stdio.h>

int main() {
  int arr[8][8];
  int j, i;
  
  // Initializing the array to 0s
  for (i=0;i<8;i++) {
    for (j=0;j<8;j++) {
      arr[i][j] = 0;
    }
  }
  
  // Filling the array with random 1s and 0s
  for (i=0;i<8;i++) {
    for (j=0;j<8;j++) {
      arr[i][j] = rand() % 2;
    }
  }
  
  // Generating the ASCII art
  for (i=0;i<8;i++) {
    for (j=0;j<8;j++) {
      if (arr[i][j] == 1) {
        printf("█");
      } else {
        printf(" ");
      }
    }
    printf("\n");
  }
  
  return 0;
}