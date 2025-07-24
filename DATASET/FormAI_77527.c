//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to generate the secure password
void generate_password(int length) {
   const char* chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+{}[];:<>,.?/|";
   int chars_length = strlen(chars);

   // seed for random number generation
   srand(time(NULL));

   // generate a random password
   char password[length];
   for(int i=0; i<length; i++) {
      password[i] = chars[rand() % chars_length];
   }
   password[length] = '\0';

   // output the password
   printf("Your secure password is: %s\n", password);
}

int main() {
   int length;

   printf("Welcome to the Secure Password Generator!\n\n");

   // get the length of the password from the user
   while(1) {
      printf("Enter the length of the password: ");
      scanf("%d", &length);

      if(length < 8) {
         printf("Please enter a length of at least 8\n");
      }
      else {
         break;
      }
   }

   // generate the password
   generate_password(length);

   return 0;
}