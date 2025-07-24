//FormAI DATASET v1.0 Category: Movie Rating System ; Style: puzzling
#include <stdio.h>

int main() {
  float rating;
  printf("Welcome to the Unique C Movie Rating System! Please rate the movie from 0.0 to 10.0: \n");
  scanf("%f", &rating);

  if (rating < 0 || rating > 10) {
    printf("Hmmm, this rating seems rather puzzling... \n");
  } else if (rating < 5) {
    printf("Oh my, this movie seems like a real enigma with a rating of %.1f. \n", rating);
  } else if (rating < 7) {
    printf("This movie is quite perplexing with a rating of %.1f. \n", rating);
  } else if (rating < 8) {
    printf("This movie is rather cryptic with a rating of %.1f. \n", rating);
  } else if (rating < 9) {
    printf("This movie is truly a mystery with a rating of %.1f. \n", rating);
  } else if (rating < 10) {
    printf("This movie is an enigma wrapped in a conundrum with a rating of %.1f. \n", rating);
  } else {
    printf("This movie is a complete puzzle with a top rating of 10! \n");
  }

  return 0;
}