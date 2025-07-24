//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 15

int main()
{
   char password[MAX_PASSWORD_LENGTH + 1] = {0};
   char password_set[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+~";
   int password_length = 0;
   int i, random_index;

   srand(time(NULL));

   printf("\nWelcome to the C Secure Password Generator!\n\n");

   printf("How many characters would you like your password to be? (maximum %d): ", MAX_PASSWORD_LENGTH);
   scanf("%d", &password_length);

   while (password_length < 1 || password_length > MAX_PASSWORD_LENGTH) {
      printf("Invalid password length. Please enter a number between 1 and %d: ", MAX_PASSWORD_LENGTH);
      scanf("%d", &password_length);
   }

   for (i=0; i<password_length; i++) {
      random_index = rand() % strlen(password_set);
      password[i] = password_set[random_index];
   }

   printf("\nYour new secure password is: %s\n\n", password);

   return 0;
}