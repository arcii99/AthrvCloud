//FormAI DATASET v1.0 Category: Recursive ; Style: introspective
#include <stdio.h>

void print_numbers(int n) {
  if(n==0) {
    printf("%d",n);
    return;
  }
  printf("%d ",n);
  print_numbers(n-1);
  printf(" %d",n);
}

int main() {
  int n;
  printf("Enter a number: ");
  scanf("%d",&n);
  printf("The numbers from 1 to %d are: ",n);
  print_numbers(n);
  return 0;
}