//FormAI DATASET v1.0 Category: Arithmetic ; Style: synchronous
#include<stdio.h>

int main()
{
  int a, b, c, d, sum, mult;
  
  printf("Enter four integers separated by space: ");
  scanf("%d %d %d %d", &a, &b, &c, &d);
  
  //Addition
  sum = a + b + c + d;
  printf("The sum of entered integers is: %d\n", sum);
  
  //Multiplication
  mult = a * b * c * d;
  printf("The multiplication of entered integers is: %d\n", mult);
  
  //Division
  if(d != 0){
    printf("The division of entered integers by %d is: %f", d, (float)(sum)/d);
  } else{
    printf("Can not divide by zero!");
  }
  
  //Subtraction
  if(a > b){
    printf("\nThe difference of %d and %d is: %d", a, b, (a-b));
  } else {
    printf("\nThe difference of %d and %d is: %d", b, a, (b-a));
  }
  
  //Modulus
  if(c != 0){
    printf("\nThe remainder of dividing %d by %d is: %d", sum, c, (sum % c));
  } else{
    printf("\nCan not perform modulus operation with zero!");
  }
  
  //Average
  printf("\nThe average of entered integers is: %f", (float)(sum)/4);
  
  return 0;
}