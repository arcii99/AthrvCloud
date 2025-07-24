//FormAI DATASET v1.0 Category: Pattern printing ; Style: puzzling
#include <stdio.h>

int main() {
  int num = 5;
  
  for(int i=0; i<num; i++){
    for(int j=num-i; j>0; j--){
      printf(" ");
    }
    for(int k=0; k<=i; k++){
      printf("%d ", k+1);
    }
    printf("\n");
  }
  
  for(int i=0; i<=num; i++) {
    for(int j=0; j<i; j++){
      printf(" ");
    }
    for(int k=i; k<=num; k++){
      printf("%d ", k+1);
    }
    printf("\n");
  }
  
  return 0;
}