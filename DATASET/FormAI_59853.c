//FormAI DATASET v1.0 Category: Movie Rating System ; Style: high level of detail
#include <stdio.h>

int main() {
   int rating;
   printf("Welcome to the C Movie Rating System!\n");
   printf("Please rate the movie you just watched on a scale of 1 to 5:\n");
   scanf("%d", &rating);

   if(rating >= 1 && rating <= 5) {
      printf("Thank you for rating the movie\n");
   } else {
      printf("Invalid rating entered\n");
      return 0;
   }

   printf("Here are some additional options:\n");
   printf("1. View the movie details\n");
   printf("2. Compare this movie with another movie\n");
   printf("3. Exit the program\n");

   int choice;
   scanf("%d", &choice);

   switch(choice) {
      case 1:
         printf("Title: Inception\n");
         printf("Director: Christopher Nolan\n");
         printf("Year Released: 2010\n");
         printf("Rating: 8.8/10 on IMDb\n");
         break;
      case 2:
         printf("Please enter the name of the movie you want to compare:\n");
         char movie[50];
         scanf("%s", movie);
         printf("Sorry, we do not have any information about %s yet.\n", movie);
         break;
      case 3:
         printf("Goodbye!\n");
         return 0;
      default:
         printf("Invalid choice entered\n");
         break;
   }
   return 0;
}