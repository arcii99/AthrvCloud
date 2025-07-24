//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: Alan Touring
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define MAX_ATTEMPTS 3 // maximum attempts allowed to enter correct password
#define MAX_PASSWORD_LEN 20 // maximum length of password allowed

int main(void) {
   char password[MAX_PASSWORD_LEN + 1] = {'\0'}; // initialize password array with NULL (0)
   char input[MAX_PASSWORD_LEN + 1] = {'\0'}; // initialize input array with NULL (0)
   int attempts = 0; // initialize the number of attempts to zero
   time_t start_time, end_time; // time variables to track the start and end time

   printf("Please enter a password (maximum length %d characters):\n", MAX_PASSWORD_LEN);
   scanf("%s", password);

   printf("Welcome to the Intrusion Detection System!\n");

   while (attempts < MAX_ATTEMPTS) {
      printf("Please enter the password to gain access:\n");
      scanf("%s", input);
      if (strcmp(password, input) == 0) {
         printf("Access granted!\n");
         break;
      }
      else {
         printf("Incorrect password, please try again.\n");
         attempts++;
      }
   }

   if (attempts == MAX_ATTEMPTS) { // max attempts reached
      printf("Maximum number of attempts reached. System is freezing for 60 seconds...\n");
      start_time = time(NULL);
      sleep(60);
      end_time = time(NULL);
      printf("System has been frozen for %ld seconds.\n", end_time - start_time);
   }

   printf("Thank you for using the Intrusion Detection System.\n");

   return 0; 
}