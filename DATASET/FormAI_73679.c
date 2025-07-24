//FormAI DATASET v1.0 Category: Browser Plugin ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Function to check if string is a palindrome
bool isPalindrome(char str[]) {
   int i = 0, j = strlen(str) - 1;
   while (i < j) {
      if (str[i++] != str[j--])
         return false;
   }
   return true;
}

// Function to reverse a string
void reverseString(char str[]) {
   int i = 0, j = strlen(str) - 1;
   while (i < j) {
      char temp = str[i];
      str[i++] = str[j];
      str[j--] = temp;
   }
}

// Callback function for browser plugin
void onPluginLoad(char address[]) {
   char *result = "This website is not a palindrome";
   if (isPalindrome(address)) {
      reverseString(address);
      result = strcat("This website is a palindrome! Reversed address: ", address);
   }
   printf("%s", result);
}

// Main function
int main() {
   char address[100];
   printf("Enter website address: ");
   scanf("%s", address);
   onPluginLoad(address);
   return 0;
}