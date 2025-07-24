//FormAI DATASET v1.0 Category: Movie Rating System ; Style: enthusiastic
#include <stdio.h>

int main() {
  int rating;
  printf("---- Welcome to the C Movie Rating System ----\n");
  
  // ask user for their rating
  printf("Please rate the movie on a scale of 1 to 10: ");
  scanf("%d", &rating);

  // check if rating is valid
  if(rating >= 1 && rating <= 10) {
    printf("Thank you for rating the movie!\n");

    // display corresponding message based on rating
    switch(rating) {
      case 1:
        printf("We're sorry you didn't enjoy the movie.\n");
        break;
      case 2:
        printf("We're sorry you didn't enjoy the movie.\n");
        break;
      case 3:
        printf("We're sorry the movie didn't meet your expectations.\n");
        break;
      case 4:
        printf("We're sorry the movie didn't meet your expectations.\n");
        break;
      case 5:
        printf("We're glad you found the movie to be average.\n");
        break;
      case 6:
        printf("We're glad you found the movie to be above average.\n");
        break;
      case 7:
        printf("We're thrilled you enjoyed the movie!\n");
        break;
      case 8:
        printf("We're thrilled you enjoyed the movie!\n");
        break;
      case 9:
        printf("Wow! You really loved the movie! Thank you!\n");
        break;
      case 10:
        printf("Wow! You really loved the movie! Thank you!\n");
        break;
      default:
        printf("Something went wrong. Please try again.\n");
        break;
    }
  } else {
    printf("Invalid rating. Please rate the movie on a scale of 1 to 10.\n");
  }
  
  return 0;
}