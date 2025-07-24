//FormAI DATASET v1.0 Category: Movie Rating System ; Style: funny
#include <stdio.h>

int main() {
  int rating;
  char movieName[50];

  printf("Welcome to the unique C Movie Rating System!\n");
  printf("Please enter the name of the movie you want to rate: ");
  scanf("%[^\n]%*c", movieName); // Get the name of the movie with spaces

  printf("How would you rate %s?\n", movieName);
  printf("Enter a number between 1-10: ");
  scanf("%d", &rating); // Get the movie rating

  printf("\nCalculating...\n\n");

  // Determine the appropriate message to show based on the movie rating
  if (rating == 10) {
    printf("Wow, %s is a masterpiece! You deserve a pat on the back for your excellent taste.\n", movieName);
  } else if (rating >= 8 && rating <= 9) {
    printf("Excellent choice! %s is definitely worth watching.\n", movieName);
  } else if (rating >= 6 && rating <= 7) {
    printf("Not bad, but %s could have been better.\n", movieName);
  } else if (rating >= 4 && rating <= 5) {
    printf("Hmm, %s doesn't seem to be your cup of tea. Better luck next time.\n", movieName);
  } else if (rating >= 2 && rating <= 3) {
    printf("Yikes. %s is definitely not recommended.\n", movieName);
  } else if (rating == 1) {
    printf("We strongly advise against watching %s. Proceed at your own risk.\n", movieName);
  } else {
    printf("Invalid rating entered. Please enter a number between 1-10.\n");
  }
  
  return 0;
}