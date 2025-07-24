//FormAI DATASET v1.0 Category: Movie Rating System ; Style: dynamic
#include <stdio.h>

int main() {
  int rating, total_ratings = 0, num_movies = 0; 
  float avg_rating = 0.0; 
  char movie_name[50], response; 

  printf("***Welcome to Unique C Movie Rating System***\n");
  
  do {
    printf("\nEnter the name of the movie: ");
    scanf("%s", movie_name);

    printf("Enter the rating (out of 5) for '%s': ", movie_name);
    scanf("%d", &rating);

    if (rating < 0 || rating > 5) {
      printf("Invalid rating entered. Please try again.\n");
      continue;
    }
    
    total_ratings += rating;
    num_movies++;
    avg_rating = (float)total_ratings / num_movies;

    printf("Thank you for rating '%s'! Current average rating is %.1f.\n", movie_name, avg_rating); 

    printf("Do you want to rate another movie? (y/n): ");
    scanf(" %c", &response);

  } while (response == 'y' || response == 'Y');
  
  printf("\nHere are the final statistics:\n"); 
  printf("Total movies rated: %d\n", num_movies); 
  printf("Average rating: %.1f\n", avg_rating); 

  return 0; 
}