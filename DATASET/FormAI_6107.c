//FormAI DATASET v1.0 Category: Recursive ; Style: energetic
#include <stdio.h>

void countDown(int n){
  if(n==0){
    printf("Blast off!\n");
  }else{
    printf("%d...\n",n);
    countDown(n-1);
  }
}

int main(){
  int startingCount = 10;
  printf("Starting countdown from %d...\n", startingCount);
  countDown(startingCount);
  return 0;
}