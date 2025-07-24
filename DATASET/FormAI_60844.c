//FormAI DATASET v1.0 Category: Pattern printing ; Style: systematic
#include <stdio.h>

int main() {
  int size;
  printf("Enter the size of pattern: ");
  scanf("%d",&size);

  //Printing the upper half of the pattern
  for(int i=1; i<=size; i++) {
    for(int j=i; j<size; j++)
      printf(" ");
    for(int k=1; k<i*2; k++)
      printf("*");
    printf("\n");
  }

  //Printing the lower half of the pattern
  for(int i=size-1; i>=1; i--) {
    for(int j=size; j>i; j--)
      printf(" ");
    for(int k=1; k<i*2; k++)
      printf("*");
    printf("\n");
  }

  return 0;
}