//FormAI DATASET v1.0 Category: Movie Rating System ; Style: high level of detail
#include <stdio.h>

int main() {
  int userRating;
  float totalRating = 0;
  float avgRating;
  int numRatings = 0;
  char movieTitle[100];
  char response[10];

  printf("Welcome to the C Movie Rating System!\n");

  do {
    printf("\nEnter the title of the movie: ");
    scanf("%s", movieTitle);

    do {
      printf("Enter your rating (1-10) for %s: ", movieTitle);
      scanf("%d", &userRating);

      if (userRating < 1 || userRating > 10) {
        printf("Invalid rating. Please enter a rating between 1 and 10.\n");
      }

    } while (userRating < 1 || userRating > 10);

    totalRating += userRating;
    numRatings++;

    avgRating = totalRating / numRatings;

    printf("\nThank you for your rating! The current average rating for %s is %.2f", movieTitle, avgRating);

    printf("\n\nWould you like to rate another movie? (y/n): ");
    scanf("%s", response);

  } while (response[0] == 'y' || response[0] == 'Y');

  printf("\nThank you for using the C Movie Rating System!\n");

  return 0;
}