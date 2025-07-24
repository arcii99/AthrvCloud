//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: funny
#include <stdio.h>

int main () {
   int pushUps = 0;
   int squats = 0;
   int sitUps = 0;
   int burpees = 0;
   
   printf("Welcome to the C Fitness Tracker!\n");
   printf("Let's get started! Enter your name: ");
   
   char name[20];
   scanf("%s", name);
   
   printf("Hi %s, let's start tracking your workouts!\n", name);
   
   while (1) {
      printf("\nWhich exercise would you like to track?\n");
      printf("1. Push-Ups\n");
      printf("2. Squats\n");
      printf("3. Sit-Ups\n");
      printf("4. Burpees\n");
      printf("5. Quit\n");
      
      int choice;
      scanf("%d", &choice);
      
      switch (choice) {
         case 1:
            printf("Enter the number of push-ups you did: ");
            
            int p;
            scanf("%d", &p);
            pushUps += p;
            
            printf("Total push-ups: %d", pushUps);
            
            break;
         
         case 2:
            printf("Enter the number of squats you did: ");
            
            int s;
            scanf("%d", &s);
            squats += s;
            
            printf("Total squats: %d", squats);
            
            break;
         
         case 3:
            printf("Enter the number of sit-ups you did: ");
            
            int su;
            scanf("%d", &su);
            sitUps += su;
            
            printf("Total sit-ups: %d", sitUps);
            
            break;
         
         case 4:
            printf("Enter the number of burpees you did: ");
            
            int b;
            scanf("%d", &b);
            burpees += b;
            
            printf("Total burpees: %d", burpees);
            
            break;
            
         case 5:
            printf("Thanks for using the C Fitness Tracker! See you next time, %s!", name);
            return 0;
            
         default:
            printf("Invalid choice!");
            break;
      }
   }
   return 0;
}