//FormAI DATASET v1.0 Category: Movie Rating System ; Style: scientific
#include <stdio.h>

int main() {
  int rating;
  float average = 0;
  int count = 0;

  printf("Welcome to the C Movie Rating System!\n");
  printf("Please rate the latest movie you watched on a scale of 1 to 10.\n");
  printf("Enter -1 to exit the program.\n");

  while (1) {
    printf("Movie rating: ");
    scanf("%d", &rating);
    if (rating == -1) {
      break;
    }
    if (rating < 1 || rating > 10) {
      printf("Invalid rating. Please enter a number between 1 and 10.\n");
      continue;
    }
    average = (average * count + rating) / (count + 1);
    count++;
    printf("Thanks for your rating!\n");
  }

  printf("\nSummary:\n");
  printf("Total number of ratings: %d\n", count);
  printf("Average rating: %.2f\n", average);
  
  if (average >= 9) {
    printf("Outstanding movie!\n");
  } else if (average >= 7) {
    printf("Good movie.\n");
  } else if (average >= 5) {
    printf("Average movie.\n");
  } else {
    printf("Bad movie.\n");
  }

  return 0;
}