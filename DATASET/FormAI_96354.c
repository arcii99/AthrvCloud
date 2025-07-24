//FormAI DATASET v1.0 Category: Movie Rating System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

int main() {
  char name[30];
  int age, rating, total_ratings = 0;
  float avg_rating = 0;

  printf("Welcome to the Unique C Movie Rating System!\n");
  printf("Please enter your name: ");
  scanf("%s", name);

  printf("Please enter your age: ");
  scanf("%d", &age);

  if (age >= 18) {
    printf("Thank you for using our system, %s.\n", name);

    while (1) {
      printf("\n\n");
      printf("Please rate the movie you watched on a scale of 1-10 (press -1 to exit): ");
      scanf("%d", &rating);

      if (rating == -1) {
        break;
      }

      if (rating < 1 || rating > 10) {
        printf("Invalid rating entered. Please enter a number from 1-10.\n");
        continue;
      }

      total_ratings++;
      avg_rating = (avg_rating * (total_ratings - 1) + rating) / total_ratings;

      printf("Thank you for rating the movie with %d.\n", rating);
      printf("The average rating of the movie is %.2f.\n", avg_rating);
    }

    printf("Thank you for using our system, %s.\n", name);
    printf("You have rated %d movies with an average rating of %.2f.\n", total_ratings, avg_rating);
  } else {
    printf("Sorry %s, you are not old enough to use our system.\n", name);
  }

  return 0;
}