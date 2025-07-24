//FormAI DATASET v1.0 Category: Random ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL)); // Seed the random number generator with the current time
  int random_number = rand() % 100; // Generate a random number between 0 and 99
  
  // Display a peaceful message based on the random number
  if (random_number < 25) {
    printf("Today is a beautiful day in nature!\n");
  } else if (random_number < 50) {
    printf("Take a deep breath and let your worries fade away.\n");
  } else if (random_number < 75) {
    printf("Find a quiet place to relax and enjoy the sound of birds singing.\n");
  } else {
    printf("Take a walk outside and appreciate the beauty of the world around you.\n");
  }
  
  return 0;
}