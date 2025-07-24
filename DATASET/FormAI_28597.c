//FormAI DATASET v1.0 Category: Smart home automation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isMotionDetected = false; //initializing motion detection to false

//function to check motion detection
void checkMotionDetection()
{
   if(isMotionDetected)
   {
      printf("Motion detected!\n");
   }
}

//function to turn lights on
void turnLightOn()
{
   printf("Lights turned ON!\n");
}

//function to turn lights off
void turnLightOff()
{
   printf("Lights turned OFF!\n");
}

//main function
int main()
{
   int option;

   printf("Welcome to Smart Home Automation\n");
   printf("Choose an option:\n");
   printf("1. Turn lights ON\n");
   printf("2. Turn lights OFF\n");
   printf("3. Check motion detection\n");
   printf("4. Exit\n");

   do
   {
      printf("Enter your option: ");
      scanf("%d", &option);

      switch(option)
      {
         case 1:
            turnLightOn();
            break;

         case 2:
            turnLightOff();
            break;

         case 3:
            checkMotionDetection();
            break;

         case 4:
            printf("Exiting program. Goodbye!\n");
            exit(0);
            break;

         default:
            printf("Invalid option. Please try again.\n");
            break;
      }
   }
   while(option != 4);

   return 0;
}