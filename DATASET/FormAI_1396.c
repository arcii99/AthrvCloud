//FormAI DATASET v1.0 Category: Movie Rating System ; Style: interoperable
#include <stdio.h>

int main() {
  int userRating, criticRating;
  char movieTitle[100];

  printf("Enter the title of the movie: ");
  scanf("%[^\n]%*c", movieTitle); // read string with spaces

  printf("Enter your rating (out of 10): ");
  scanf("%d", &userRating);

  if (userRating < 0 || userRating > 10) {
    printf("Invalid rating. Please enter a rating between 0 and 10.\n");
    return 0;
  }

  printf("Enter the critic rating (out of 100): ");
  scanf("%d", &criticRating);

  if (criticRating < 0 || criticRating > 100 ) {
    printf("Invalid rating. Please enter a rating between 0 and 100.\n");
    return 0;
  }

  double avgRating = (userRating + (double) criticRating/10) / 2;

  printf("\nMovie Title: %s\n", movieTitle);
  printf("User Rating: %d / 10\n", userRating);
  printf("Critic Rating: %d / 100\n", criticRating);

  if (avgRating >= 7.5) {
    printf("Average Rating: %.1f\n", avgRating);
    printf("This movie is a hit!\n");
  } else if (avgRating >= 5.0) {
    printf("Average Rating: %.1f\n", avgRating);
    printf("This movie is average.\n");
  } else {
    printf("Average Rating: %.1f\n", avgRating);
    printf("This movie is a flop.\n");
  }

  return 0;
}