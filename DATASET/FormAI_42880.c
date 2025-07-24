//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   srand(time(NULL));
   int dronePos = rand() % 100;
   int userInput;
   int tries = 0;
   
   printf("Welcome to the C Drone Remote Control program!\n");
   printf("You've got 10 attempts to guess where the drone is located.\n");
   printf("The drone is somewhere between 0 and 100.\n");
   
   do {
       printf("Enter your guess: ");
       scanf("%d", &userInput);
       
       if(userInput < dronePos) {
           printf("The drone is higher than %d\n", userInput);
       } else if (userInput > dronePos) {
           printf("The drone is lower than %d\n", userInput);
       }
       
       tries++;
   } while(userInput != dronePos && tries < 10);
   
   if(userInput == dronePos) {
       printf("Congratulations! You've successfully located the drone!\n");
       printf("You did it in %d attempts.\n", tries);
   } else {
       printf("Game over. The drone was located at %d.\n", dronePos);
   }
   
   return 0;
}