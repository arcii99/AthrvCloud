//FormAI DATASET v1.0 Category: Movie Rating System ; Style: light-weight
#include <stdio.h>

int main() {
  int rating;

  // Display rating options and prompt user for input
  printf("Welcome to the Unique C Movie Rating System!\n");
  printf("Please rate the movie on a scale of 1-5:\n");
  printf("1 - Terrible\n");
  printf("2 - Bad\n");
  printf("3 - Okay\n");
  printf("4 - Good\n");
  printf("5 - Excellent\n");

  // Get user input for rating
  scanf("%d", &rating);

  // Print rating message based on user input
  switch (rating) {
    case 1:
      printf("Sorry to hear that you found the movie terrible.\n");
      break;
    case 2:
      printf("We're sorry the movie didn't meet your expectations.\n");
      break;
    case 3:
      printf("We are happy to hear that you found the movie okay.\n");
      break;
    case 4:
      printf("Great to hear that you enjoyed the movie.\n");
      break;
    case 5:
      printf("Excellent! We are glad that you enjoyed the movie.\n");
      break;
    default:
      printf("Invalid rating input! Please try again.\n");
      break;
  }
  
  return 0;
}