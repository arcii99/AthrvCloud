//FormAI DATASET v1.0 Category: Movie Rating System ; Style: irregular
#include <stdio.h>

int main() {
  int rating;
  
  printf("Welcome to the Unique C Movie Rating System!\n");
  printf("Please enter your rating (1-10): ");
  scanf("%d", &rating);

  if (rating < 1 || rating > 10) {
    printf("Invalid rating, please enter a number between 1 and 10.\n");
  } else {
    printf("Thank you for rating the movie %d out of 10!\n", rating);
    
    if (rating == 1) {
      printf("Yikes, that's a terrible rating. We're sorry you didn't enjoy the movie.\n");
    } else if (rating > 1 && rating < 5) {
      printf("It sounds like this movie wasn't for you. Thanks for giving it a chance.\n");
    } else if (rating >= 5 && rating < 8) {
      printf("Glad to hear it was enjoyable! Any suggestions on how we can improve?\n");
    } else if (rating >= 8 && rating < 10) {
      printf("Wow, thanks for the high rating! We're thrilled to hear you enjoyed the movie.\n");
    } else if (rating == 10) {
      printf("Congratulations, you've given the movie a perfect rating! This is a huge accomplishment.\n");
    }
  }
  
  return 0;
}