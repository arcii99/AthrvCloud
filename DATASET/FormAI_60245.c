//FormAI DATASET v1.0 Category: Pattern printing ; Style: surrealist
#include <stdio.h>

int main() {
  int i, j, k, l, n;

  printf("Enter an odd number: ");
  scanf("%d", &n);

  for(i=1; i<=n; i++) {
    for(j=1; j<=n; j++) {
      if(i==1 || i==n || j==1 || j==n) {
        printf("C ");
      } else {
        if(i%2==0) {
          if(j%2==0) {
            printf("P ");
          } else {
            printf("O ");
          }
        } else {
          if(j%2==0) {
            printf("D ");
          } else {
            printf("E ");
          }
        }
      }
    }
    printf("\n");
  }
  
  return 0;
}