//FormAI DATASET v1.0 Category: Pattern printing ; Style: protected
#include<stdio.h>

int main(){
  int i,j,n=15;
  // Generating the first half of the pattern
  for(i=0;i<n;i++){
    for(j=0;j<=i;j++){
      printf("*");
    }
    printf("\n");
  }

  // Generating the second half of the pattern
  for(i=n-1;i>0;i--){
    for(j=0;j<i;j++){
      printf("*");
    }
    printf("\n");
  }

  return 0;
}