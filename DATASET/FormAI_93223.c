//FormAI DATASET v1.0 Category: Error handling ; Style: inquisitive
#include<stdio.h>
#include<stdlib.h>

int main(){

  int num1, num2, result;

  printf("Enter First Number: ");
  scanf("%d", &num1);

  printf("Enter Second Number: ");
  scanf("%d", &num2);

  if(num2 == 0){

    printf("Error! Division by zero is not allowed!");
    printf("Please enter a non-zero divisor.\n");
    printf("Enter divisor: ");
    scanf("%d", &num2);

    if(num2 == 0){
      printf("Error! You have entered invalid input again!. Exiting program........");
      exit(0);  //exit program gracefully
    }
  }

  result = num1/ num2;
  printf("The result of division is : %d\n", result);

  return 0;
}