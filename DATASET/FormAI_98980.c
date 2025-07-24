//FormAI DATASET v1.0 Category: Movie Rating System ; Style: post-apocalyptic
#include <stdio.h>

int main() {
  int rating;
  printf("Welcome to the post-apocalyptic movie rating system.\n");
  printf("Please rate the movie from 1 to 10, where 1 is terrible and 10 is excellent: ");
  scanf("%d", &rating);

  if (rating >= 1 && rating <= 3) {
    printf("Sorry, this movie is not worth watching in a post-apocalyptic world.\n");
  }
  else if (rating >= 4 && rating <= 6) {
    printf("This movie is mediocre. It might be worth watching if you have nothing else to do.\n");
  }
  else if (rating >= 7 && rating <= 9) {
    printf("This is a good movie. It will entertain you in the post-apocalyptic world.\n");
  }
  else if (rating == 10) {
    printf("Wow, this is an excellent movie! It will definitely make your post-apocalyptic life better.\n");
  }
  else {
    printf("Invalid rating. Please rate the movie from 1 to 10.\n");
  }

  return 0;
}