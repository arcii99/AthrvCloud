//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: Romeo and Juliet
#include <stdio.h>

int main() {
  // Pixel art generator for Romeo and Juliet
  int r = 255, g = 0, b = 0; // starting color is red
  int pixelCount = 50; // number of pixels to generate

  for (int i = 0; i < pixelCount; i++) {
    printf("\033[38;2;%d;%d;%dm@\033[0m", r, g, b); // print pixel in RGB color
    if (i % 10 == 0) { // add line break after every 10 pixels
      printf("\n");
    }

    // change color based on pixel position
    if (i < 10 || i > 39) { // red pixels at top and bottom
      r = 255;
      g = 0;
      b = 0;
    } else if (i >= 10 && i < 20) { // green pixels for Romeo
      r = 0;
      g = 255;
      b = 0;
    } else if (i >= 30 && i < 40) { // blue pixels for Juliet
      r = 0;
      g = 0;
      b = 255;
    } else { // white pixels for background
      r = 255;
      g = 255;
      b = 255;
    }
  }

  return 0;
}