//FormAI DATASET v1.0 Category: Funny ; Style: enthusiastic
#include <stdio.h>

int main() {
  int num, sum = 0;

  printf("Enter a positive integer: ");
  scanf("%d", &num);

  for (int i = 1; i <= num; i++) {
    sum += i;
  }

  printf("The sum of 1 to %d is %d\n", num, sum);

  if (sum % 2 == 0) {
    printf("Wow! %d is an even number!\n", sum);
  } else {
    printf("Yippee! %d is an odd number!\n", sum);
  }

  printf("Let's double the sum now!\n");
  sum *= 2;
  printf("The new sum is %d\n", sum);

  printf("Let's convert the sum to binary now!\n");
  printf("The binary value of %d is ", sum);
  for (int i = 31; i >= 0; i--) {
    printf("%d", (sum >> i) & 1);
  }
  printf("\n");

  printf("Finally, let's print out the ASCII characters that match the sum!\n");
  printf("The ASCII characters for %d are: ", sum);
  for (int i = 0; i < 4; i++) {
    printf("%c", sum % 127);
    sum /= 127;
  }
  printf("\n");
  
  return 0;
}