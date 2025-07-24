//FormAI DATASET v1.0 Category: Movie Rating System ; Style: ephemeral
#include <stdio.h>

// function to calculate the movie quality index
float get_movie_quality_index(float rating, int release_year) {
  float index = rating * (2021 - release_year);
  return index;
}

int main() {
  char movie_name[50];
  float critic_rating, user_rating;
  int release_year;

  // get input from user
  printf("Enter movie name: ");
  scanf("%[^\n]", movie_name);
  printf("Enter critic rating (out of 10): ");
  scanf("%f", &critic_rating);
  printf("Enter user rating (out of 5): ");
  scanf("%f", &user_rating);
  printf("Enter release year: ");
  scanf("%d", &release_year);

  // call function to get movie quality index
  float movie_quality_index = get_movie_quality_index((critic_rating + user_rating)/2, release_year);

  // determine rating system based on movie quality index
  if (movie_quality_index > 50000) {
    printf("Movie: %s\nQuality Index: %.2f\nRating: Blockbuster\n", movie_name, movie_quality_index);
  } else if (movie_quality_index > 30000) {
    printf("Movie: %s\nQuality Index: %.2f\nRating: Super Hit\n", movie_name, movie_quality_index);
  } else if (movie_quality_index > 15000) {
    printf("Movie: %s\nQuality Index: %.2f\nRating: Hit\n", movie_name, movie_quality_index);
  } else if (movie_quality_index > 5000) {
    printf("Movie: %s\nQuality Index: %.2f\nRating: Semi-Hit\n", movie_name, movie_quality_index);
  } else {
    printf("Movie: %s\nQuality Index: %.2f\nRating: Flop\n", movie_name, movie_quality_index);
  }

  return 0;
}