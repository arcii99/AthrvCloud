//FormAI DATASET v1.0 Category: Pattern printing ; Style: artistic
#include <stdio.h>

int main() {
  int row, col, space;

  for(row=1; row<=7; row++) {
    for(space=1; space<=7-row; space++) {
      printf(" ");
    }
    for(col=1; col<=row*2-1; col++) {
      if(col==1 || col==row*2-1 || row==7) {
        printf("*");
      } else {
        printf(" ");
      }
    }
    printf("\n");
  }
  
  for(row=6; row>=1; row--) {
    for(space=1; space<=7-row; space++) {
      printf(" ");
    }
    for(col=1; col<=row*2-1; col++) {
      if(col==1 || col==row*2-1 || row==7) {
        printf("*");
      } else {
        printf(" ");
      }
    }
    printf("\n");
  }

  return 0;
}