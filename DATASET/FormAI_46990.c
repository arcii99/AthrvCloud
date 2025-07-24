//FormAI DATASET v1.0 Category: Pattern printing ; Style: brave
#include <stdio.h>

int main() {
  printf("Behold the mighty C pattern printing program!\n");

  int n = 5;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n - i; j++) {
        printf(" ");
    }
    for (int k = 1; k <= i; k++) {
        printf("* ");
    }
    printf("\n");
  }

  printf("\n");

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n - i; j++) {
        printf(" ");
    }
    for (int k = 1; k <= 2*i - 1; k++) {
        printf("*");
    }
    printf("\n");
  }

  printf("\n");

  int m = n + 1;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n - i; j++) {
        printf(" ");
    }
    for (int k = 1; k <= i; k++) {
        if (k == 1 || k == i) {
            printf("* ");
        }
        else {
            printf("  ");
        }
    }
    printf("\n");
  }

  for (int i = n-1; i >= 1; i--) {
    for (int j = 1; j <= n-i; j++) {
        printf(" ");
    }
    for (int k = 1; k <= i; k++) {
        if (k == 1 || k == i) {
            printf("* ");
        }
        else {
            printf("  ");
        }
    }
    printf("\n");
  }

  printf("\n");

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n - i; j++) {
        printf(" ");
    }
    for (int k = 1; k <= 2*i - 1; k++) {
        if (k == 1 || k == 2*i - 1) {
            printf("*");
        }
        else {
            printf(" ");
        }
    }
    printf("\n");
  }

  for (int i = n-1; i >= 1; i--) {
    for (int j = 1; j <= n-i; j++) {
        printf(" ");
    }
    for (int k = 1; k <= 2*i - 1; k++) {
        if (k == 1 || k == 2*i - 1) {
            printf("*");
        }
        else {
            printf(" ");
        }
    }
    printf("\n");
  }

  printf("\n");

  for(int i=1;i<=n;i++){
    for(int j=i;j<=n-1;j++){
        printf(" ");
    }
    for(int j=1;j<=2*i-1;j++){
        printf("*");
    }
    printf("\n");
  }

  for(int i=n-1;i>=1;i--){
    for(int j=n-1;j>=i;j--){
        printf(" ");
    }
    for(int j=1;j<=2*i-1;j++){
        printf("*");
    }
    printf("\n");
  }

  return 0;
}