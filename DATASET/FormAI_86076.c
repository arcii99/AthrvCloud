//FormAI DATASET v1.0 Category: Movie Rating System ; Style: puzzling
#include<stdio.h>
#include<stdlib.h>

int main(){
  int rating;
  printf("Welcome to our unique C Movie Rating System! Please rate the movie you have seen on a scale of 1 to 10.\n");
  scanf("%d", &rating);
  
  if(rating <= 0){
    printf("Invalid rating. Please rate the movie on a scale of 1 to 10.\n");
    scanf("%d", &rating);
  }
  else if(rating == 1){
    printf("Wow, you really didn't like the movie, did you?\n");
  }
  else if(rating < 5){
    printf("We're sorry to hear that you didn't enjoy the movie.\n");
  }
  else if(rating == 5){
    printf("It sounds like you found the movie to be just okay.\n");
  }
  else if(rating < 8){
    printf("We're glad to hear that you enjoyed the movie!\n");
  }
  else if(rating >= 8){
    printf("Wow, it sounds like you really loved the movie!\n");
  }
  printf("Thank you for rating the movie. We hope you continue to enjoy our unique C Movie Rating System!\n");
  return 0;
}