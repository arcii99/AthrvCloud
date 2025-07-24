//FormAI DATASET v1.0 Category: Random ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  printf("Hi there! I am a C program that generates random numbers from 1 to 10.\n");
  printf("Let's see how I do it:\n");

  // Set random seed
  srand(time(NULL));

  // Generate and print 10 random numbers from 1 to 10
  printf("Here are 10 random numbers from 1 to 10:\n");
  for (int i = 1; i <= 10; i++)
  {
    int random_num = rand() % 10 + 1;
    printf("%d ", random_num);
  }
  printf("\n");

  // Generate and print a random number between user-defined range
  int lower_range, upper_range;
  printf("Now let's try something else. Please enter a lower range: ");
  scanf("%d", &lower_range);
  printf("And an upper range: ");
  scanf("%d", &upper_range);

  // Check for invalid input
  while (upper_range <= lower_range)
  {
    printf("Invalid input. Please enter a valid range.\n");
    printf("Lower range: ");
    scanf("%d", &lower_range);
    printf("Upper range: ");
    scanf("%d", &upper_range);
  }

  int random_num = rand() % (upper_range - lower_range + 1) + lower_range;
  printf("Your random number between %d and %d is: %d\n", lower_range, upper_range, random_num);

  printf("Did you see that? I can generate random numbers in a range too!\n");

  return 0;
}