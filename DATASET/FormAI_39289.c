//FormAI DATASET v1.0 Category: Scientific ; Style: happy
#include<stdio.h>

int main() {

  int num, first=0, second=1, next;
  
  printf("Enter the number of terms to display: ");
  scanf("%d", &num);
  
  printf("\nHere's the Fibonacci sequence up to the %dth term:\n", num);
  
  for(int i=0; i<num; i++) {
    if(i<=1) {
      next=i;
    } else {
      next=first+second;
      first=second;
      second=next;
    }
    printf("%d ",next);
  }
  
  printf("\n\nThat was fun, wasn't it? Let's do it again some time!");
  
  return 0;
}