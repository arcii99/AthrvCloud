//FormAI DATASET v1.0 Category: Movie Rating System ; Style: funny
#include <stdio.h>

int main() {
  int popcorn = 0;
  int soda = 0;
  int rating = 0;

  printf("Welcome to the C Movie Rating System!\n");
  printf("Please rate the movie on a scale of 1 to 10:\n");

  scanf("%d", &rating);

  if(rating < 1) {
    printf("There's no way the movie was that bad! Did you even watch it?\n");
  } else if(rating > 10) {
    printf("Wow, a perfect 10! Did the movie change your life or something?\n");
    popcorn++;
    soda++;
  } else {
    printf("Thanks for your rating!\n");
  }

  printf("Did you get popcorn during the movie? (1 for yes, 0 for no)\n");

  scanf("%d", &popcorn);

  if(popcorn) {
    printf("Great choice! What's a movie without popcorn?\n");
  } else {
    printf("No popcorn? You must not be a movie buff.\n");
  }

  printf("How about soda? (1 for yes, 0 for no)\n");

  scanf("%d", &soda);

  if(soda) {
    printf("A soda is the perfect companion to popcorn during a movie. Cheers!\n");
  } else {
    printf("No soda? That's okay, but you're missing out on the full movie experience.\n");
  }

  printf("Thanks for using the C Movie Rating System! Enjoy your day.\n");

  return 0;
}