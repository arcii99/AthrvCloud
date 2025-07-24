//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: surrealist
#include <stdio.h>

int main() {
  int clouds = 5;
  int sun = 1;
  int rain = 0;

  while (clouds > 0) {
    printf("There are %d clouds in the sky.\n", clouds);
    if (sun && !rain) {
      printf("The sun is shining bright.\n");
    } else if (!sun && !rain) {
      printf("It's dark and gloomy.\n");
    } else if (rain) {
      printf("It's pouring outside.\n");
    }

    if (clouds == 3) {
      printf("Suddenly, a bolt of lightning strikes!\n");
    } else if (clouds == 2) {
      printf("A rainbow appears in the sky.\n");
    }
    clouds--;

    if (clouds == 0 && sun) {
      printf("The sun sets in the horizon.\n");
    } else if (clouds == 0 && !sun) {
      printf("It's pitch black outside.\n");
    }
  }

  return 0;
}