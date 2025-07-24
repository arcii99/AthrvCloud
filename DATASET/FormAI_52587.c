//FormAI DATASET v1.0 Category: Pattern printing ; Style: energetic
#include <stdio.h>

int main() {
  int i, j, k;
  for(i=1; i<=5; i++) {
    for(j=1; j<=i; j++) {
      printf("%d ", j);
    }
    for(k=5-i; k>=1; k--){
      printf("  ");
    }
    for(j=i; j>=1; j--) {
      printf("%d ", j);
    }
    printf("\n");
  }
  for(i=4; i>=1; i--) {
    for(j=1; j<=i; j++) {
      printf("%d ", j);
    }
    for(k=5-i; k>=1; k--){
      printf("  ");
    }
    for(j=i; j>=1; j--) {
      printf("%d ", j);
    }
    printf("\n");
  }
  return 0;
}