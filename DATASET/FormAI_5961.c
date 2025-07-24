//FormAI DATASET v1.0 Category: Movie Rating System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>

struct rating {
   char name[50];
   int user_id;
   float rating;
};

int main() {
   int i, n, total_users, option, user_id, flag = 0, count = 0;
   float avg_rating = 0;
   char movie_name[100], user_name[50];

   printf("Enter the name of the movie: ");
   fgets(movie_name, 100, stdin);

   printf("Enter the total number of users: ");
   scanf("%d", &total_users);

   struct rating ratings[total_users];

   for (i = 0; i < total_users; i++) {
      printf("\nEnter the user ID: ");
      scanf("%d", &ratings[i].user_id);

      printf("Enter the user name: ");
      scanf("%s", ratings[i].name);

      printf("Enter the rating for this movie (out of 10): ");
      scanf("%f", &ratings[i].rating);

      avg_rating += ratings[i].rating;

      count += 1;

      printf("\nRating submitted successfully!");
   }

   avg_rating /= total_users;

   printf("\n\nThe average rating for the movie \"%s\" is %.2f", movie_name, avg_rating);

   while (1) {
      printf("\n\nWhat would you like to do?\n1. View all ratings\n2. Search for a user\n3. Quit\nEnter your option: ");
      scanf("%d", &option);

      if (option == 1) {
         printf("\nAll Ratings for the movie \"%s\":", movie_name);
         for (i = 0; i < total_users; i++) {
            printf("\nUser ID: %d  User Name: %s  Rating: %.2f", ratings[i].user_id, ratings[i].name, ratings[i].rating);
         }
      } else if (option == 2) {
         printf("\nEnter the user ID: ");
         scanf("%d", &user_id);

         for (i = 0; i < total_users; i++) {
            if (ratings[i].user_id == user_id) {
               printf("\nUser ID: %d  User Name: %s  Rating: %.2f", ratings[i].user_id, ratings[i].name, ratings[i].rating);
               flag = 1;
               break;
            }
         }

         if (flag == 0) {
            printf("\nUser with ID %d not found!", user_id);
         }

         flag = 0;

      } else if (option == 3) {
         printf("\nThank you for using our Movie Rating System!");
         break;
      } else {
         printf("\nInvalid option selected!");
      }
   }

   return 0;
}