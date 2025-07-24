//FormAI DATASET v1.0 Category: Pattern printing ; Style: grateful
#include<stdio.h>

int main(){
  int n = 7;
  int i,j,k;

  for(i=1;i<=n;i++){
    for(j=1;j<=n-i;j++){
      printf(" ");
    }

    for(k=1;k<=i;k++){
      printf("* ");
    }
    printf("\n");
  }

  for(i=1;i<=n-1;i++){
    for(j=1;j<=i;j++){
      printf(" ");
    }

    for(k=1;k<=n-i;k++){
      printf("* ");
    }
    printf("\n");
  }

  printf("\n\n");

  for(i=1;i<=n;i++){
    for(j=1;j<=n-i;j++){
      printf(" ");
    }

    for(k=1;k<=i;k++){
      printf("%d ", k);
    }
    printf("\n");
  }

  for(i=1;i<=n-1;i++){
    for(j=1;j<=i;j++){
      printf(" ");
    }

    for(k=1;k<=n-i;k++){
      printf("%d ",k);
    }
    printf("\n");
  }

  printf("\n\n");

  for(i=1;i<=n;i++){
    for(j=1;j<=n-i;j++){
      printf(" ");
    }

    for(k=1;k<=i;k++){
      printf("%c ", i+96);
    }
    printf("\n");
  }

  for(i=1;i<=n-1;i++){
    for(j=1;j<=i;j++){
      printf(" ");
    }

    for(k=1;k<=n-i;k++){
      printf("%c ", n-i+96);
    }
    printf("\n");
  }

  return 0;
}