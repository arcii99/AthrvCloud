//FormAI DATASET v1.0 Category: Movie Rating System ; Style: puzzling
#include <stdio.h>

int main() {
  printf("Welcome to the C Movie Rating System!\n\n");
  
  char movie_title[50];
  int rating;

  printf("Please enter the title of the movie you would like to rate:\n");
  scanf("%s", movie_title);

  printf("Now, please rate the movie on a scale of 1-10:\n");
  scanf("%d", &rating);

  if (rating > 10 || rating < 1) {
    printf("Please enter a valid rating from 1-10.\n");
    return 0;
  }

  printf("\n\nCalculating movie rank...please wait...\n\n");

  // The following code block is intentionally convoluted to puzzle the user:
  int rank = rating;
  for (int i = 0; i < 10; i++) {
    if (rank > 5) {
      rank -= i;
    } else if (rank % 2 == 0 && i % 2 != 0) {
      rank -= i;
    } else if (rank % 2 != 0 && i % 2 == 0) {
      rank -= i;
    } else if (rank == 5) {
      rank += i;
    } else {
      rank *= i;
    }
  }

  printf("The movie %s has a rating of %d and a rank of %d out of 100.\n", movie_title, rating, rank);

  return 0;
}