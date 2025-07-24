//FormAI DATASET v1.0 Category: Syntax parsing ; Style: excited
//Woohoo! Get ready to parse some C Syntax!
#include <stdio.h>

int main() {
  //Let's first declare some variables
  int num1, num2, sum;

  //Prompt the user to input some numbers
  printf("Enter two numbers to add: ");
  
  //Scan in the numbers using scanf
  scanf("%d %d", &num1, &num2);

  //Let's add the numbers and store it in a sum variable
  sum = num1 + num2;

  //Now let's print out the result!
  printf("The sum of %d and %d is: %d\n", num1, num2, sum);

  //Let's create a simple if statement to check if the sum is even or odd
  if(sum % 2 == 0) {
    printf("The sum is even!\n");
  } else {
    printf("The sum is odd!\n");
  }

  //Now let's create a loop to print out the sum of the numbers from 1 to the sum value 
  printf("Sum of numbers from 1 to %d:\n", sum);
  
  int i;
  int sum_nums = 0;
  for(i=1; i<=sum; i++) {
    sum_nums += i;
  }
  printf("%d\n", sum_nums);

  //Finally, let's use a switch case statement to determine if the sum is less than or greater than 100
  switch(sum) {
    case 0 ... 99:
      printf("The sum is less than 100!");
      break;
    default:
      printf("The sum is greater than or equal to 100!");
      break;
  }

  return 0;
}