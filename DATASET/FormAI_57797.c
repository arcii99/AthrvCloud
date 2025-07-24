//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: happy
#include<stdio.h>
#include<stdlib.h>

void happyMessage(char* message) {
   printf("Hooray! %s\n", message);
}

int main() {
   happyMessage("Your Intrusion Detection System is up and running!");

   // declare variables
   int attempts = 3;
   char password[10];

   // problem setup
   printf("\nEnter password to access the system:\n");

   // password checking loop
   while(attempts > 0) {
      printf("\nAttempt left: %d\n",attempts);
      scanf("%s",password);

      // password correct
      if(strcmp(password, "happyCoding") == 0) {
         happyMessage("Congratulations! Password is correct.");
         break;
      }
      // password incorrect
      else {
         printf("\nOops, wrong password! Please try again.\n");
         attempts--;
      }
   }

   // determine if the user has accessed the system or not
   if(attempts == 0) {
      happyMessage("Intrusion detected! Alerting the authorities!");
   } else {
      happyMessage("Welcome to the system Sir/Madam!");
   }

   // end the program
   happyMessage("Program Terminated. Have a Nice Day!");
   return 0;
}