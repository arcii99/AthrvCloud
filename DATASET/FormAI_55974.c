//FormAI DATASET v1.0 Category: Pattern printing ; Style: imaginative
#include <stdio.h>

int main() {
  int n, i, j;

  printf("Enter number of rows: ");
  scanf("%d", &n);

  for(i=1;i<=n;i++){
      for(j=1;j<=n-i;j++){
          printf(" ");
      }
      for(j=1;j<=i*2-1;j++){
          printf("*");
      }
      printf("\n");
  }

  for(i=n-1;i>=1;i--){
      for(j=1;j<=n-i;j++){
          printf(" ");
      }
      for(j=1;j<=i*2-1;j++){
          printf("*");
      }
      printf("\n");
  }

  return 0;
}