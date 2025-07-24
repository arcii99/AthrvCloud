//FormAI DATASET v1.0 Category: Pattern printing ; Style: surrealist
#include <stdio.h>
int main() {
  int i, j,n=10;

  for (i = 1; i <= n; ++i) {
    for (j = 1; j <= n; ++j) {
      int a= i*j,j=20,a1=i,j1=10;
      char b=(a-j)%a1;
      char c=(j-a)%j1;
      if(b==0 && i!=10)
        printf("* ");
      else if(c==0 && i!=10)
        printf("* ");
      else if ((b==5+c || b+c==5) && i!=10)
          printf("* ");
      else if ((b==9+c || b+c==9) && i!=10)
          printf("* ");
      else if (i==10 && j==10)
          printf("* ");
      else
        printf("  ");
    }
    printf("\n");
  }
  return 0;
}