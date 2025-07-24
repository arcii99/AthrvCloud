//FormAI DATASET v1.0 Category: Random ; Style: synchronous
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
  int i, n, rand_num;
  time_t t;
  
  //Initializes the random number generator
  srand((unsigned) time(&t));

  //Asks user for the number of random numbers to be generated
  printf("Enter the number of random numbers to be generated: ");
  scanf("%d", &n);

  //Generates n random numbers and prints them
  printf("Random numbers generated are:\n");
  for (i = 1; i <= n; i++) {
    rand_num = rand();
    printf("%d\n", rand_num);
  }

  return 0;
}