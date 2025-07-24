//FormAI DATASET v1.0 Category: Movie Rating System ; Style: surprised
#include<stdio.h>
#include<stdlib.h>

int main() {
  int rating;
  printf("Welcome to our unique C Movie Rating System! Please rate the movie you just watched, from 1 to 10.\n");
  scanf("%d", &rating);
  if (rating >= 1 && rating <= 10) {
    printf("You rated the movie %d out of 10. Thank you for your rating!\n", rating);
  } else {
    printf("Invalid rating. Please try again with a number from 1 to 10.\n");
    exit(0);
  }
  
  printf("Would you like to see the average rating of this movie? Please enter Y or N.\n");
  char answer;
  scanf(" %c", &answer);
  if (answer == 'Y') {
    int numRatings;
    printf("Please enter the number of ratings for this movie.\n");
    scanf("%d", &numRatings);

    if (numRatings <= 0) {
      printf("Invalid number of ratings. Goodbye!\n");
      exit(0);
    }

    int totalRating = rating * numRatings;
    printf("The movie has a total rating of %d out of %d possible points.\n", totalRating, numRatings * 10);

    float avgRating = (float) totalRating / numRatings;
    printf("The average rating for this movie is %.1f out of 10.\n", avgRating);

    if (avgRating < 5) {
      printf("Looks like this movie needs some improvement. We hope the producers will take your feedback into account for the next one!\n");
    } else {
      printf("Congratulations! This movie is a hit!\n");
    }
  } else if (answer == 'N') {
    printf("Thank you for your rating! Goodbye!\n");
  } else {
    printf("Invalid input. Goodbye!\n");
  }

  return 0;
}