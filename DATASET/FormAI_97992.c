//FormAI DATASET v1.0 Category: Movie Rating System ; Style: mathematical
#include <stdio.h>

int main() {
   int rating[5]; // array to hold the movie ratings
   float average = 0.0; // variable to calculate the average rating
   int i;
   printf("Enter rating out of 10 for story, direction, acting, cinematography and overall : \n");
   // accepting user input for movie ratings
   for (i = 0; i < 5; i++) {
      printf("Enter rating for aspect %d: ", i + 1);
      scanf("%d" ,&rating[i]);
   }
   // calculating the average rating
   for (i = 0; i < 5; i++) {
      average += rating[i];
   }
   average /= 5.0;
   printf("The average rating is : %f\n", average);
   if (average >= 9.0) {
      printf("Excellent movie! Definitely a must watch!\n");
   } else if (average >= 8.0) {
      printf("Very good movie. Highly recommended!\n");
   } else if (average >= 7.0) {
      printf("Good movie. Worth watching!\n");
   } else if (average >= 6.0) {
      printf("Average movie. Watch it if you have nothing else to do!\n");
   } else {
      printf("Below average movie. Not worth your time!\n");
   }
   return 0;
}