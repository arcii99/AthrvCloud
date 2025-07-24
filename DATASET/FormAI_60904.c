//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

int main() {
  
  int num, sum = 0, temp;
  printf("Please enter a number: ");
  scanf("%d", &num);
  temp = num;

  while(num > 0) {
    // Getting the last digit of the number
    int digit = num % 10;
    // Add the last digit to the sum
    sum += digit;
    // Dividing the number by 10 to remove the last digit
    num /= 10;
  }

  // Computing the checksum value
  int checksum = (sum % 10 == 0) ? 0 : (10 - sum % 10);

  printf("Sum of all digits in %d is %d\n", temp, sum);
  printf("Checksum value is %d\n", checksum);

  return 0;
}