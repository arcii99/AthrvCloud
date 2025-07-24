//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: surrealist
#include <stdio.h>

int main() {
  int input, sum = 0;
  printf("Welcome to the Surrealist Checksum Calculator!\n");
  printf("Please enter your secret number: ");
  scanf("%d", &input);
  while (input != 0) {
    int digit = input % 10;
    sum += (digit * 7);
    input /= 10;
    printf("The mad scientist's machine has absorbed the digit %d.\n", digit);
  }
  printf("Don't be alarmed! The machine has finished deciphering your number and has calculated the checksum...\n");
  int checksum = (sum / 7) + 42;
  printf("Your Cosmic Checksum is: %d\n", checksum);
  printf("You are now one step closer to unlocking the secrets of the multiverse!\n");

  return 0;
}