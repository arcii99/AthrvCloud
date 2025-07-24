//FormAI DATASET v1.0 Category: Pattern printing ; Style: ephemeral
#include<stdio.h>
int main() {
  int rows, i, j, k;
  printf("Enter the number of rows: ");
  scanf("%d", &rows);
  for(i=1;i<=rows;i++) {
    for(j=i;j<rows;j++)
      printf(" ");
    for(k=1;k<=i;k++) {
      printf("*");
      if(i>1&&k<i) {
        printf(" ");
      }
    }
    for(k=1;k<i;k++) {
      if(i>1&&k<i) {
        printf(" ");
    }
      printf("*");
    } 
    printf("\n");
  }   
  for(i=rows-1;i>=1;i--) {
    for(j=rows;j>i;j--)
      printf(" ");
    for(k=1;k<=i;k++) {
      printf("*");
      if(i>1&&k<i) {
        printf(" ");
      }
    }
    for(k=1;k<i;k++) {
        if(i>1&&k<i) {
          printf(" ");
    }
      printf("*");
    }
    printf("\n");
  }
  return 0;
}