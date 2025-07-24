//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL));

  int width, height, color;
  char pixel;

  printf("Welcome to the C Pixel Art Generator!\n");
  printf("Please enter the width of your image: ");
  scanf("%d", &width);
  printf("Please enter the height of your image: ");
  scanf("%d", &height);
  printf("What color do you want to use? Enter 1 for red, 2 for green, or 3 for blue: ");
  scanf("%d", &color);

  printf("Generating your masterpiece...\n");

  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      if (rand() % 2 == 0) {
        pixel = 'C';
      } else {
        pixel = ' ';
      }
      printf("\033[3%d;%dm%c\033[0m", color, rand() % 7 + 31, pixel);
    }
    printf("\n");
  }

  printf("Congratulations on your new C Pixel Art!\n");

  return 0;
}