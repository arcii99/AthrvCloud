//FormAI DATASET v1.0 Category: Movie Rating System ; Style: genious
#include<stdio.h>

int main(){
  int rating;
  printf("Welcome to the Unique C Movie Rating System! \n");
  printf("Please rate the movie on a scale of 1-10: \n");
  scanf("%d", &rating);
  if(rating < 1 || rating > 10){
    printf("Invalid rating! Rating must be between 1-10. \n");
    return 0;
  }
  if(rating >= 1 && rating < 4){
    printf("Oh no! You rated the movie as 'Terrible.' \n");
  } else if(rating >= 4 && rating < 6){
    printf("You rated the movie as 'Average.' \n");
  } else if(rating >= 6 && rating < 8){
    printf("Great job! You have rated the movie as 'Good.' \n");
  } else {
    printf("Brilliant! You have rated the movie as 'Excellent.' \n");
  }
  printf("Thanks for using the Unique C Movie Rating System. Goodbye! \n");
  return 0;
}