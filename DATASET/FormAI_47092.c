//FormAI DATASET v1.0 Category: Movie Rating System ; Style: Alan Touring
#include<stdio.h>

int main(){
   int movie_rating;

   // Taking input from user
   printf("Enter the movie rating (1-10): ");
   scanf("%d", &movie_rating);

   // Checking the movie rating
   if(movie_rating < 5){
      printf("This is a bad movie. It needs improvement!\n");
   }
   else if(movie_rating < 7){
      printf("This is an average movie.\n");
   }
   else{
      printf("This is a great movie! A must watch!\n");
   }

   return 0;
}