//FormAI DATASET v1.0 Category: Movie Rating System ; Style: shape shifting
#include <stdio.h>

int main() {
  float rating;

  printf("Welcome to the Shape Shifting Movie Rating System!\n");
  printf("Please enter your movie rating: ");
  scanf("%f", &rating);

  if (rating <= 5.0) {
    printf("Our system has determined that this movie is a Shapeless Blob.\n");
    printf("We do not recommend watching this movie under any circumstances.\n");
  } else if (rating <= 6.0) {
    printf("Our system has determined that this movie is a Formless Mass.\n");
    printf("We urge caution when watching this movie, as it may cause confusion.\n");
  } else if (rating <= 7.0) {
    printf("Our system has determined that this movie is a Squishy Square.\n");
    printf("This movie is neither remarkable nor regrettable, and can be watched at your own discretion.\n");
  } else if (rating <= 8.0) {
    printf("Our system has determined that this movie is a Triangular Triumph.\n");
    printf("This movie is highly recommended and is sure to provide an enjoyable experience for most viewers.\n");
  } else if (rating <= 9.0) {
    printf("Our system has determined that this movie is a Marvelous Octagon.\n");
    printf("This movie is a true masterpiece and is a must-watch for any movie lover.\n");
  } else {
    printf("Our system has determined that this movie is a Transcendent Sphere.\n");
    printf("This movie is not only a cinematic achievement but a cultural phenomenon. We highly recommend watching it.\n");
  }

  return 0;
}