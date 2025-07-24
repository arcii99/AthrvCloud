//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: happy
#include <stdio.h>
#include <string.h>

/* This is a happy Intrusion Detection System program! */
int main(void)
{
   printf("Welcome to our IDS System!\n");
   printf("We are here to keep you and your system safe!\n");
 
   /* Define some variables */
   char input[100];
   char password[] = "happyIDSrocks";
   int attempts = 0;
   
   /* Start of the loop */
   while(attempts < 3)
   {
      /* Ask the user to enter the password */
      printf("Please enter the password to access the system: ");
      fgets(input, 100, stdin);
      input[strcspn(input, "\n")] = 0; // Remove the newline character from the input
      
      /* Check if the password is correct */
      if(strcmp(input, password) == 0)
      {
         printf("Access granted! Welcome back.\n");
         break; // Exit the loop
      }
      else
      {
         printf("Access denied! Please try again.\n");
         attempts++; // Increment the attempts counter
      }
   }
   
   /* Check if the maximum number of attempts has been reached */
   if(attempts == 3)
   {
      printf("Too many failed attempts! The system will now shutdown for 30 seconds.\n");
      /* Do something cool here like playing some happy music or showing some funny pictures! :) */
      sleep(30); // Pause the program for 30 seconds
   }
   
   /* Happy end of the IDS program! */
   printf("Thank you for using our IDS System!\n");
   printf("Stay safe and have a great day!\n");
   return 0;
}