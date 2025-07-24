//FormAI DATASET v1.0 Category: Movie Rating System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

// function to calculate rating based on input criteria 
int calculateRating(int acting, int storyline, int specialEffects) {
  int total = acting + storyline + specialEffects;  //add scores
  int rating;
  
  // determine rating based on total score
  if (total > 20) {
    rating = 5;
  } else if (total > 15) {
    rating = 4;
  } else if (total > 10) {
    rating = 3;
  } else if (total > 5) {
    rating = 2;
  } else {
    rating = 1;
  }
  
  return rating;
}

int main() {
  int actingScore, storylineScore, specialEffectsScore;
  int movieRating;
  
  printf("Welcome to the C Movie Rating System.\n");
  printf("Please rate the following criteria on a scale of 1-10\n");

  // get user input for scores
  printf("Acting: ");
  scanf("%d", &actingScore);
  
  printf("Storyline: ");
  scanf("%d", &storylineScore);
  
  printf("Special Effects: ");
  scanf("%d", &specialEffectsScore);
  
  // calculate rating
  movieRating = calculateRating(actingScore, storylineScore, specialEffectsScore);
  
  // display rating
  printf("\nBased on your scores, the movie's rating is: %d\n", movieRating);
  
  return 0;
}