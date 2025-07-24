//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: inquisitive
#include <stdio.h>
#include <string.h>

int main() {
   char input[1000]; // Setup our input array
   
   printf("Enter a string to check if it's a palindrome: "); // Ask the user for input
   scanf("%s", input); //Read user input

   int length = strlen(input); // Get the length of our input
   int palindrome = 1; // Setup a boolean variable to represent our whether or not our input is a palindrome

   for(int i = 0; i < length/2; i++) { // Check half the string since the second half is the same as the first half (since it's a palindrome)
      if(input[i] != input[length-i-1]) { // Check if the first and last characters match, if they don't, it's not a palindrome
         palindrome = 0; // Set our palindrome variable to false
         break; // Exit the loop since we know it's not a palindrome
      }
   }

   if(palindrome) { // Check if our palindrome variable is still true
      printf("%s is a palindrome!\n", input); // If it is, print that our input string is a palindrome
   } else {
      printf("%s is not a palindrome :(\n", input); // If it isn't, print that our input string is not a palindrome
   }

   return 0;
}