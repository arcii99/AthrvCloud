//FormAI DATASET v1.0 Category: Educational ; Style: innovative
#include <stdio.h>

int main() {
  int number;
  printf("Enter a number: ");
  scanf("%d", &number);
  
  if(number % 2 == 0) {
    printf("%d is even.\n", number);
  } else {
    printf("%d is odd.\n", number);
  }
  
  int i;
  printf("The first %d odd numbers are: ", number);
  for(i = 1; i <= number; i++) {
    printf("%d ", 2 * i - 1);
  }
  printf("\n");
  
  int fibonacci[number + 1];
  fibonacci[0] = 0;
  fibonacci[1] = 1;
  for(i = 2; i <= number; i++) {
    fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
  }
  printf("The first %d numbers in the Fibonacci sequence are: ", number);
  for(i = 0; i < number; i++) {
    printf("%d ", fibonacci[i]);
  }
  printf("\n");
  
  int sum = 0;
  for(i = 1; i <= number; i++) {
    sum += i;
  }
  printf("The sum of the first %d positive integers is %d.\n", number, sum);
  
  return 0;
}