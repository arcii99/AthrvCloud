//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   int entered = 0; 
   int scareChance = 5; 
   int doorChoice = 0; 

   srand(time(NULL)); 

   printf("*** Welcome to the Haunted House Simulator ***\n");
   printf("You have entered a dark and creepy mansion!\n");

   do {
      printf("\nYou are now in the entrance hall. The door to your left leads to the living room\n");
      printf("The door to your right leads to the kitchen. Which door do you choose? (1 for left, 2 for right)\n");
      scanf("%d", &doorChoice);

      if(doorChoice == 1) {
         printf("\nYou have entered the living room.\n");
         entered++; 
         if(rand() % scareChance == 0) {
            printf("SPOOKY!\n");
         }
      } else if(doorChoice == 2) {
         printf("\nYou have entered the kitchen.\n");
         entered++; 
         if(rand() % scareChance == 0) {
            printf("SPOOKY!\n");
         }
      } else {
         printf("\nThat is not a valid choice.\n");
      }

   }while(entered < 3); 

   printf("\nYou have successfully visited 3 rooms!\n");
   printf("Thank you for playing the Haunted House Simulator!\n");

   return 0;
}