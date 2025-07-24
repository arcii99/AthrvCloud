//FormAI DATASET v1.0 Category: Movie Rating System ; Style: systematic
#include <stdio.h>

int main() {
  char movieTitle [100];
  int rating, totalRating = 0, numRatings = 0;
  float avgRating;
  
  printf("Welcome to the C Movie Rating System!\n");
  
  printf("Please enter the title of the movie: ");
  fgets(movieTitle, 100, stdin);
  
  printf("Please rate the movie out of 10: ");
  scanf("%d", &rating);
  
  while (rating > 0 && rating < 11) {
    totalRating += rating;
    numRatings++;
    
    printf("Thank you for your rating! Enter another rating or 0 to exit: ");
    scanf("%d", &rating);
  }
  
  if (numRatings == 0) {
    printf("No valid ratings were entered. Goodbye!\n");
    return 0;
  }
  
  avgRating = (float) totalRating / numRatings;
  
  printf("\n\n********** SUMMARY **********\n");
  printf("Movie title: %s", movieTitle);
  printf("Average rating: %.1f\n", avgRating);
  printf("Number of ratings: %d\n", numRatings);
  
  if (avgRating >= 8.0) {
    printf("This movie is highly recommended!");
  } else if (avgRating >= 6.0) {
    printf("This movie is worth watching!");
  } else {
    printf("This movie is not recommended.");
  }
  
  return 0;
}