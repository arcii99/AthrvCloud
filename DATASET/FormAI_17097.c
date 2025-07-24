//FormAI DATASET v1.0 Category: Movie Rating System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

int main() {
  int age, rating;
  char movie_title[50];
  printf("Welcome to the C Movie Rating System!\n");
  printf("Please enter the title of the movie you'd like to rate: ");
  scanf("%s", movie_title);
  
  printf("Great! Now, please enter your age: ");
  scanf("%d", &age);
  
  if (age >= 18) {
    printf("Thank you! Please rate the movie from 1 to 10: ");
    scanf("%d", &rating);
    if (rating >= 1 && rating <= 4) {
      printf("We're sorry to hear that you didn't enjoy the movie.\n");
    }
    else if (rating >= 5 && rating <= 7) {
      printf("Glad to hear that you liked the movie!\n");
    }
    else if (rating >= 8 && rating <= 10) {
      printf("Wow! It seems like you absolutely loved the movie!\n");
    }
    else {
      printf("Invalid rating, please enter a number between 1 to 10.\n");
    }
  }
  else {
    printf("We're sorry, but you are not old enough to rate this movie. Please come back when you're older.\n");
  }
  
  return 0;
}