//FormAI DATASET v1.0 Category: Smart home light control ; Style: peaceful
#include <stdio.h>

int main() {
   int time, choice;

   printf("Hello! Welcome to your peaceful smart home light control.\n");
   printf("What time is it? (Please enter an integer between 0 and 24):\n");
   scanf("%d", &time);

   if (time > 24 || time < 0) {
      printf("Invalid time, please try again.\n");
      return 0;
   }

   printf("\nIt is currently %d:00.\n", time);

   printf("\nWhat would you like to do? (Please enter a number):\n");
   printf("1. Turn on all lights.\n");
   printf("2. Turn off all lights.\n");
   printf("3. Set a specific light brightness.\n");
   scanf("%d", &choice);

   switch(choice) {
      case 1:
         printf("\nTurning on all lights...\n");
         break;
      case 2:
         printf("\nTurning off all lights...\n");
         break;
      case 3:
         int lightChoice, brightness;
         printf("\nWhich light would you like to adjust? (Please enter a number):\n");
         printf("1. Living room light.\n");
         printf("2. Bedroom light.\n");
         scanf("%d", &lightChoice);

         if (lightChoice != 1 && lightChoice != 2) {
            printf("Invalid choice, please try again.");
            return 0;
         }

         printf("\nWhat brightness level would you like to set? (Please enter a number between 0 and 100):\n");
         scanf("%d", &brightness);

         if (brightness > 100 || brightness < 0) {
            printf("Invalid brightness level, please try again.\n");
            return 0;
         }

         if (lightChoice == 1) {
            printf("\nSetting living room light brightness to %d%%...\n", brightness);
         } else {
            printf("\nSetting bedroom light brightness to %d%%...\n", brightness);
         }
         break;
      default:
         printf("\nInvalid choice, please try again.\n");
         return 0;
   }

   printf("\nThank you for using our smart home light control system. Have a peaceful day!\n");
   return 0;
}