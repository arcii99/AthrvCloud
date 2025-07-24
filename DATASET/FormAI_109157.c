//FormAI DATASET v1.0 Category: Funny ; Style: satisfied
#include <stdio.h>

int main() {
  int num = 12345;
  printf("I am feeling joyous today!\n");
  printf("Here is a unique program to make you smile:\n\n");
  
  // Printing the number
  printf("The given number is: %d\n", num);

  // Sum of all the digits of the number
  int sum = 0;
  while(num > 0) {
    sum += num%10;
    num /= 10;
  }
  printf("The sum of all the digits of the number is: %d\n", sum);

  // Reversing the number
  int reversed_num = 0;
  int original_num = num;
  while(original_num > 0) {
    reversed_num = reversed_num * 10 + original_num % 10;
    original_num /= 10;
  }
  printf("The reversed number is: %d\n", reversed_num);

  // Checking if the number is a palindrome
  if(reversed_num == num) {
    printf("The number is a palindrome!\n");
  } else {
    printf("The number is not a palindrome!\n");
  }

  printf("\nHope this program made you smile!\n");
  return 0;
}