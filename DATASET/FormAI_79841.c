//FormAI DATASET v1.0 Category: Movie Rating System ; Style: irregular
#include <stdio.h>

int main() {
  int rating;
  printf("Welcome to the unique C Movie Rating System!\n");
  printf("Please enter the rating for the movie you just watched (1-10): ");
  scanf("%d", &rating);

  if (rating < 1) {
    printf("Error: rating cannot be less than 1\n");
  } else if (rating > 10) {
    printf("Error: rating cannot be greater than 10\n");
  } else {
    printf("Thank you for your rating!\n");
    printf("Here is our unique analysis of your rating:\n");

    switch (rating) {
      case 1:
        printf("Did you accidentally watch a home video of a family vacation?\n");
        break;
      case 2:
        printf("We recommend avoiding this movie at all costs.\n");
        break;
      case 3:
        printf("We're sorry you wasted your time on this movie.\n");
        break;
      case 4:
        printf("This movie could have been better.\n");
        break;
      case 5:
        printf("A mediocre movie, but still worth the watch.\n");
        break;
      case 6:
        printf("This movie was good, but not great.\n");
        break;
      case 7:
        printf("A solid movie with a few flaws.\n");
        break;
      case 8:
        printf("This is a must-watch movie!\n");
        break;
      case 9:
        printf("One of the best movies we've seen in a while.\n");
        break;
      case 10:
        printf("A true masterpiece!\n");
        break;
      default:
        printf("Error: invalid rating\n");
        break;
    }
  }

  return 0;
}