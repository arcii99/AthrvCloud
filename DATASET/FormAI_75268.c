//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000
#define MAX_NUM 100

int main()
{
  // Declare the array and the variables for the loop
  int array[ARRAY_SIZE];
  int i, j;
  int max = 0;
  int min = MAX_NUM;

  // Randomly populate the array with integers between 0 and MAX_NUM
  srand(time(NULL));
  for(i = 0; i < ARRAY_SIZE; i++)
  {
    array[i] = rand() % MAX_NUM;
  }

  // Find the maximum and minimum values in the array
  for(j = 0; j < 1000; j++)
  {
    for(i = 0; i < ARRAY_SIZE; i++)
    {
      if(array[i] > max)
      {
        max = array[i];
      }
      if(array[i] < min)
      {
        min = array[i];
      }
    }
  }

  // Print the results
  printf("Maximum: %d\n", max);
  printf("Minimum: %d\n", min);


  return 0;
}