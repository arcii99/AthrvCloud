//FormAI DATASET v1.0 Category: Movie Rating System ; Style: synchronous
#include <stdio.h>

int main() {
  int rating;
  
  printf("Welcome to the Unique C Movie Rating System!\n");
  printf("Please rate the movie you watched today out of 10: ");
  scanf("%d", &rating);

  if (rating >= 8) {
    printf("Wow! That's a great rating!\n");
    printf("We highly recommend you to share this wonderful experience on social media.\n");
  } else if (rating >= 5 && rating <= 7) {
    printf("Ah, not bad, but there's still room for improvement.\n");
    printf("We suggest you to watch a similar movie in our collection.\n");
  } else {
    printf("Oh no, that's not a very good rating.\n");
    printf("We apologize for the inconvenience you faced and we'll look into it immediately.\n");
    printf("Please contact support for any further assistance.\n");
  }

  return 0;
}