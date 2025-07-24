//FormAI DATASET v1.0 Category: Movie Rating System ; Style: ephemeral
#include <stdio.h>

// Function to calculate the rating
int calculate_rating(int likes, int dislikes){
  return (likes * 100) / (likes + dislikes);
}

// Function to display the movie name and its corresponding rating
void display_rating(char movie_name[100], int likes, int dislikes){
  int rating = calculate_rating(likes, dislikes);
  printf("\nMovie: %s", movie_name);
  printf("\nRating: %d%%", rating);
}

int main(){
  char movie_name[100];
  int likes = 0, dislikes = 0;
  char choice;

  while(1){
    printf("\nEnter the name of the movie: ");
    scanf("%s", &movie_name);

    printf("\nEnter the number of likes: ");
    scanf("%d", &likes);

    printf("\nEnter the number of dislikes: ");
    scanf("%d", &dislikes);

    display_rating(movie_name, likes, dislikes);
    
    printf("\nWould you like to rate another movie? (y/n): ");
    scanf("%s", &choice);

    if (choice != 'y'){
      break;
    }
  }

  return 0;
}