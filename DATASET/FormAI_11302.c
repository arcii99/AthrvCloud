//FormAI DATASET v1.0 Category: Random ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
  printf("Welcome to the exciting world of random numbers!\n");
  printf("Get ready to see some insane stuff happen!\n");
  
  srand(time(NULL)); // seed the random number generator with the current time
  
  int num = rand() % 100; // generate a random number between 0 and 99
  
  printf("The random number is: %d\n", num);
  
  bool isPrime = true;
  
  for (int i = 2; i < num; i++) {
    if (num % i == 0) { // check if the number is divisible by any integer other than 1 and itself
      isPrime = false;
      break; // exit the loop early if the number is not prime
    }
  }
  
  if (isPrime) {
    printf("The random number is PRIME!\n");
    printf("This is incredible! We just generated a random prime number!\n");
    printf("I am so excited I could dance!\n");
  } else {
    printf("The random number is NOT prime. Bummer.\n");
    printf("But hey, at least we're learning something new, right?\n");
    printf("Keep exploring the world of randomness and you never know what you might find!\n");
  }
  
  return 0;
}