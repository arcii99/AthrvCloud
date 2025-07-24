//FormAI DATASET v1.0 Category: Recursive ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int recursive_function(int num) { // Here's the function we'll be recursively calling
  if (num == 0) { // Our base case - when num equals 0, we stop calling the function
    printf("Bam! Zero has been reached!\n");
    return 0; // We don't really need to return anything since we're not doing anything with the result, but let's do it just for the sake of it
  } else {
    printf("%d... ", num);
    return recursive_function(num - 1); // Here we call the function again, this time with num-1
  }
}

int main() {
  int starting_num;
  srand(time(NULL)); // Random seed to make sure we get a different starting number every time we run the program
  starting_num = rand() % 100 + 1; // Random number between 1 and 100
  printf("Let's start counting down from %d!\n", starting_num);
  printf("(Press any key to start the countdown...) ");
  getchar(); // Wait for user input
  printf("\n");
  recursive_function(starting_num); // Call our recursive function with the starting num
  printf("And that's it! Thanks for counting down with me :)\n");
  return 0;
}