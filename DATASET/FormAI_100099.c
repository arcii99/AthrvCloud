//FormAI DATASET v1.0 Category: Password management ; Style: Ada Lovelace
#include <stdio.h>
#include <string.h>

#define MAX_USERS 10
#define MAX_PASSWORD_LENGTH 20

struct user {
   char username[MAX_PASSWORD_LENGTH];
   char password[MAX_PASSWORD_LENGTH];
};

int main() {
   struct user users[MAX_USERS];
   char entered_username[MAX_PASSWORD_LENGTH];
   char entered_password[MAX_PASSWORD_LENGTH];
   int i, user_exists, attempts;

   // Fill in some users for demo purposes
   strcpy(users[0].username, "ada_lovelace");
   strcpy(users[0].password, "computing");
   strcpy(users[1].username, "grace_hopper");
   strcpy(users[1].password, "programming");
   strcpy(users[2].username, "alan_turing");
   strcpy(users[2].password, "enigma");

   // Welcome message
   printf("Welcome to the Password Management System!\n");
   printf("Please enter your username and password to access your account.\n");

   // Loop until user enters correct credentials or exceeds maximum attempts
   attempts = 0;
   do {
      // Ask user for username and password
      printf("Enter your username: ");
      scanf("%s", entered_username);
      printf("Enter your password: ");
      scanf("%s", entered_password);

      // Check if entered credentials match any existing user
      user_exists = 0;
      for (i = 0; i < MAX_USERS; i++) {
         if (strcmp(entered_username, users[i].username) == 0 && strcmp(entered_password, users[i].password) == 0) {
            user_exists = 1;
            break;
         }
      }

      // If the user exists, show welcome message
      if (user_exists) {
         printf("\nWelcome, %s!\n", entered_username);
         printf("You have successfully logged in.\n");

         // Ask user if they want to change password
         char change_password;
         printf("Would you like to change your password? (Y/N) ");
         scanf(" %c", &change_password);

         // If the user wants to change password, prompt for new one and store it
         if (change_password == 'Y' || change_password == 'y') {
            char new_password[MAX_PASSWORD_LENGTH];
            printf("Enter new password (up to %d characters): ", MAX_PASSWORD_LENGTH - 1);
            scanf("%s", new_password);
            strcpy(users[i].password, new_password);
            printf("Password successfully changed.\n");
         }

         // Exit program
         return 0;
      }
      // If the user does not exist, show error message and increment attempt counter
      else {
         printf("\nIncorrect username or password. Please try again.\n");
         attempts++;
      }
   } while (attempts < 3);

   // If the maximum number of attempts is reached, show error message and exit program
   printf("\nMaximum number of attempts exceeded. Account locked.\n");
   return 1;
}