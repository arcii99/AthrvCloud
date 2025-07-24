//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: funny
#include <stdio.h>
#include <string.h>

int main() {
   char password[100];
   int upper = 0, lower = 0, digit = 0, special = 0, length = 0;
   
   printf("Hello there! Please enter your password:");
   scanf("%s", password);
   
   length = strlen(password); //Get the length of the password
   
   for(int i=0;i<length;i++) {
      if(password[i]>='A' && password[i]<='Z') //Check for uppercase letters
         upper++;
      else if(password[i]>='a' && password[i]<='z') //Check for lowercase letters
         lower++;
      else if(password[i]>='0' && password[i]<='9') //Check for digits
         digit++;
      else //Assume everything else is a special character
         special++;
   }
   
   printf("Analyzing password strength...\n");
   
   if(length >= 8 && upper >= 1 && lower >= 1 && digit >= 1 && special >=1) { //Strong password condition
      printf("Congratulations! Your password is strong! Nobody will ever be able to guess it... unless they know you well enough to guess your favorite 4 letter word followed by the year you were born :)\n");
   }
   else if(length < 8) { //Weak password condition
      printf("Sorry, but your password is weak. It needs to be at least 8 characters long. How about adding the name of your first pet to the end of your current password? No one will ever suspect a thing...\n");
   }
   else { //Medium password condition
      printf("Your password is just okay. It could be better. Here's a suggestion: Add a random exclamation point at the end of your password. Trust me, it makes all the difference!\n");
   }
   
   return 0;
}