//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: introspective
#include <stdio.h>

int main() {
   int userInput;

   printf("Please enter a command for the drone: \n");
   scanf("%d", &userInput);

   switch(userInput) {
      case 1 :
         printf("\nThe drone has taken off!\n");
         break;
      case 2 :
         printf("\nThe drone is hovering.\n");
         break;
      case 3 :
         printf("\nThe drone is moving forward.\n");
         break;
      case 4 :
         printf("\nThe drone is moving backward.\n");
         break;
      case 5 :
         printf("\nThe drone is turning left.\n");
         break;
      case 6 :
         printf("\nThe drone is turning right.\n");
         break;
      case 7 :
         printf("\nThe drone is ascending.\n");
         break;
      case 8 :
         printf("\nThe drone is descending.\n");
         break;
      case 9 :
         printf("\nThe drone has landed safely.\n");
         break;
      default :
         printf("\nInvalid command entered.\n");
   }

   return 0;
}