//FormAI DATASET v1.0 Category: Arithmetic ; Style: synchronous
#include<stdio.h>

int main(){
  int a, b;
  printf("Enter the first number:");
  scanf("%d", &a);
  printf("Enter the second number:");
  scanf("%d", &b);

  printf("The sum of %d and %d is %d\n", a, b, a+b);
  printf("The difference of %d and %d is %d\n", a, b, a-b);
  printf("The multiplication of %d and %d is %d\n", a, b, a*b);
  if(b==0){
    printf("The division is not possible!");
  } else {
    printf("The division of %d and %d is %d\n", a, b, a/b);
  }
  printf("The remainder of %d and %d is %d\n", a, b, a%b);
  return 0;
}