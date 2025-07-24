//FormAI DATASET v1.0 Category: Random ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random numbers recursively
void generateRandom(int n, int arr[])
{
  if(n == 0)
    return;
    
  generateRandom(n-1, arr);
  arr[n-1] = rand() % 100; // Generate a random number between 0 and 99
}

int main()
{
  srand(time(NULL)); // Set the random seed based on the current time
  
  int arr[10];
  generateRandom(10, arr);
  
  printf("Here are 10 random numbers generated recursively: ");
  for(int i = 0; i < 10; i++)
    printf("%d ", arr[i]);
  
  return 0;
}