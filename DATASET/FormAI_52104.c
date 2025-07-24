//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to create a random pixel art
void randomArt(int n) {
  int r, g, b;
  // loop through each row of the image
  for (int i = 0; i < n; i++) {
    // loop through each pixel column of the image
    for (int j = 0; j < n; j++) {
      r = rand() % 256; // assign a random value from 0-255 to red
      g = rand() % 256; // assign a random value from 0-255 to green
      b = rand() % 256; // assign a random value from 0-255 to blue
      // print the pixel in RGB format
      printf("\033[38;2;%d;%d;%dm█\033[0m ", r, g, b);
    }
    printf("\n"); // move to next line
  }
}

int main() {
  srand(time(NULL)); // seed the random number generator
  int n;
  printf("Enter size of image (in pixels): ");
  scanf("%d", &n); // get size of image from user
  randomArt(n);
  return 0;
}