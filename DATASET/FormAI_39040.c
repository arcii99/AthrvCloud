//FormAI DATASET v1.0 Category: Movie Rating System ; Style: energetic
#include <stdio.h>

int main() {
  int rating;

  printf("Welcome to the Unique C Movie Rating System!\n");
  printf("Please rate the movie you just watched on a scale of 1 to 10:\n");
  scanf("%d", &rating);

  printf("\nCalculating rating...\n");

  switch(rating) {
    case 1:
      printf("\nWow, that was a terrible movie. We give it a rating of 1 out of 10.\n");
      break;
    case 2:
      printf("\nWe're sorry you had to sit through that. We give it a rating of 2 out of 10.\n");
      break;
    case 3:
      printf("\nNot the best, but not the worst. We give it a rating of 3 out of 10.\n");
      break;
    case 4:
      printf("\nA mediocre movie. We give it a rating of 4 out of 10.\n");
      break;
    case 5:
      printf("\nAn average movie. We give it a rating of 5 out of 10.\n");
      break;
    case 6:
      printf("\nA decent movie. We give it a rating of 6 out of 10.\n");
      break;
    case 7:
      printf("\nA good movie. We give it a rating of 7 out of 10.\n");
      break;
    case 8:
      printf("\nAn excellent movie. We give it a rating of 8 out of 10.\n");
      break;
    case 9:
      printf("\nAn outstanding movie. We give it a rating of 9 out of 10.\n");
      break;
    case 10:
      printf("\nAn absolute masterpiece. We give it a rating of 10 out of 10.\n");
      break;
    default:
      printf("\nInvalid rating. Please rate the movie on a scale of 1 to 10.\n");
      break;
  }

  return 0;
}