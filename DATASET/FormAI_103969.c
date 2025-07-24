//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool is_prime(int num) {
  if(num < 2) {
    return false;
  }
  for(int i = 2; i < num; i++) {
    if(num % i == 0) {
      return false;
    }
  }
  return true;
}

int main() {
  int num;
  bool continue_program = true;
  printf("Welcome to the Prime Number Generator! \n");
  while(continue_program) {
    printf("Please enter a number greater than 1 to generate all prime numbers from 2 to your number.\n");
    scanf("%d", &num);
    if(num <= 1) {
      printf("Invalid input. Please enter a number greater than 1.\n");
      continue;
    }
    printf("Prime numbers generated: ");
    for(int i = 2; i <= num; i++) {
      if(is_prime(i)) {
        printf("%d ", i);
      }
    }
    printf("\n");
    printf("Do you want to continue? (y/n)\n");
    char user_response;
    scanf(" %c", &user_response);
    if(user_response != 'y' && user_response != 'Y') {
      continue_program = false;
    }
  }
  printf("Thank you for using the Prime Number Generator! Goodbye.");
  return 0;
}