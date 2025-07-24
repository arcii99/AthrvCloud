//FormAI DATASET v1.0 Category: Movie Rating System ; Style: excited
#include<stdio.h>
#include<stdlib.h>

int main()
{
  int rating;
  printf("Welcome to the C Movie Rating System! \n");
  
  printf("Please rate the movie you have watched out of 10: ");
  scanf("%d", &rating);

  if(rating < 0 || rating > 10) {
    printf("Invalid rating. Please enter a rating between 0 and 10.\n");
    return 1;
  }
  
  printf("Based on your rating of %d, we would like to suggest:\n", rating);

  if(rating >= 9) {
    printf("Excellent choice! We suggest you watch The Shawshank Redemption.\n");
  } else if(rating >= 8) {
    printf("You have great taste in movies! You should watch The Godfather.\n");
  } else if(rating >= 7) {
    printf("Good choice! Try watching The Dark Knight.\n");
  } else if(rating >= 6) {
    printf("Not bad! You might enjoy watching The Matrix.\n");
  } else if(rating >= 5) {
    printf("You are a generous rater! Check out The Avengers.\n");
  } else if(rating >= 4) {
    printf("Hmm, you might like watching Die Hard.\n");
  } else if(rating >= 3) {
    printf("Interesting rating. We recommend you watch The Twilight Saga:\n");
  } else if(rating >= 2) {
    printf("Really? Well, you might enjoy Sharknado.\n");
  } else {
    printf("Are you sure you watched a movie? How about watching Birdemic?\n");
  }

  return 0;
}