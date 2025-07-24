//FormAI DATASET v1.0 Category: Scientific ; Style: creative
#include <stdio.h>

int main() {
  int num, remainder, reversed = 0;

  printf("Please enter an integer: ");
  scanf("%d", &num);

  while(num != 0) {
    remainder = num % 10;
    reversed = reversed * 10 + remainder;
    num /= 10;
  }

  printf("The reversed number is: %d", reversed);

  // Now let's check if the reversed number is a palindrome
  int original_num = num;
  int temp = reversed;
  while(temp != 0) {
    remainder = temp % 10;
    num = num * 10 + remainder;
    temp /= 10;
  }

  if(original_num == num) {
    printf("\n%d is a palindrome", original_num);
  } else {
    printf("\n%d is not a palindrome", original_num);
  }

  return 0;
}