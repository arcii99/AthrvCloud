//FormAI DATASET v1.0 Category: Movie Rating System ; Style: funny
#include <stdio.h>

int main() {

  int rating;
  char movie[50];
  printf("Welcome to the Unique C Movie Rating System! Please enter the movie you would like to rate: ");
  scanf("%s", movie);
  printf("You entered %s. Now, on a scale from 1 to 10, how would you rate %s? ", movie, movie);
  scanf("%d", &rating);

  if (rating <= 0) {
    printf("Well, that's not a very nice rating. ");
  } else if (rating == 1) {
    printf("Thanks for the barely passing score. ");
  } else if (rating == 2) {
    printf("Ok, we'll take it, but don't expect any awards. ");
  } else if (rating >= 3 && rating <= 5) {
    printf("Meh, it's not terrible, but it's not great either. ");
  } else if (rating >= 6 && rating <= 8) {
    printf("Alright, someone liked it. ");
  } else if (rating == 9) {
    printf("Wow, that's a high score. ");
  } else if (rating == 10) {
    printf("Holy cow, we've got a winner! ");
  }

  printf("Thanks for rating %s. Your opinion matters to us, even if we don't agree with it.\n", movie);
  
  return 0;
}