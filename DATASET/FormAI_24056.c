//FormAI DATASET v1.0 Category: Pattern printing ; Style: surrealist
#include <stdio.h>

int main() {
  int i, j, k=0;
  
  for(i=1; i<=10; i++) {
    for(j=1; j<=10; j++) {
      if(j==1 || j==10 || j==i || j==(11-i)){
        printf("* ");
      }
      else if(j%2==0){
        printf("& ");
      }
      else{
        printf("^ ");
      }
      k++;
    }
    printf("\n");
  }
  return 0;
}