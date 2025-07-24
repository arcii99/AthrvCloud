//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printStars(int num){
   //Function to print stars for decoration
   for (int i = 0; i < num; i++){
      printf("*");
   }
   printf("\n");
}

void printMessage(char* message){
   //Function to print message with decoration
   printStars(20);
   printf("%s\n", message);
   printStars(20);
}

int main() {
   //Initialize variables
   int planetHealth = 100;
   int spaceshipHealth = 100;
   int asteroidDamage = 10;
   int chanceOfAsteroid = 50;
   int choice;

   srand(time(0)); //Seed random number generator

   printf("Welcome to Procedural Space Adventure!\n");

   do {
      //Print options
      printStars(20);
      printf("What do you want to do?\n");
      printf("1. Attack the Planet\n");
      printf("2. Repair your Spaceship\n");
      printf("3. End the Game\n");

      //Take input from user
      printf("Enter your choice (1-3): ");
      scanf("%d", &choice);

      switch (choice) {
         case 1:
            //Attack the planet
            if (rand() % 100 < chanceOfAsteroid) {
               //Asteroid attack occurs
               printf("Oh no! Your Spaceship was hit by an Asteroid!\n");
               spaceshipHealth -= asteroidDamage;
               if (spaceshipHealth <= 0) {
                  printMessage("Your Spaceship was destroyed! Game Over.");
                  return 0;
               }
            }
            else {
               //Planet attack occurs
               printf("You attack the Planet!\n");
               planetHealth -= rand() % 20 + 1;
               if (planetHealth <= 0) {
                  printMessage("Congratulations! You have saved the galaxy!");
                  return 0;
               }
            }
            break;

         case 2:
            //Repair the spaceship
            printf("You repair your Spaceship!\n");
            spaceshipHealth += rand() % 20 + 1;
            if (spaceshipHealth > 100) {
               spaceshipHealth = 100;
            }
            break;

         case 3:
            //End the game
            printMessage("Thanks for playing!");
            return 0;

         default:
            //Invalid choice
            printf("Invalid choice!\n");
            break;
      }

      //Print status
      printf("Your Spaceship Health: %d\n", spaceshipHealth);
      printf("Planet Health: %d\n", planetHealth);
   } while (1);

   return 0;
}