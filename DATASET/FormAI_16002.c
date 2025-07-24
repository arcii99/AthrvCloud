//FormAI DATASET v1.0 Category: Movie Rating System ; Style: satisfied
#include<stdio.h>
#include<stdlib.h>

int main(){
   int rating;
   printf("Welcome to the C Movie Rating System\n");
   printf("Please rate the movie out of 5: ");
   scanf("%d", &rating);

   if(rating >= 5){
      printf("Wow, you loved the movie! We rate it 5 stars!\n");
   }
   else if(rating >= 4){
      printf("Great! We rate the movie 4 stars.\n");
   }
   else if(rating >= 3){
      printf("Not bad. We rate the movie 3 stars.\n");
   }
   else if(rating >= 2){
      printf("Sorry to hear that. We rate the movie 2 stars.\n");
    }
   else{
      printf("Terrible. We rate the movie 1 star.\n");
   }

   printf("Thanks for using the C Movie Rating System. Have a great day!");

   return 0;
}