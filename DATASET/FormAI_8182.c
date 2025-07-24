//FormAI DATASET v1.0 Category: String manipulation ; Style: cheerful
#include <stdio.h>
#include <string.h>

int main() {
   char greeting[200] = "Hello, world!";
   
   printf("Original greeting: %s\n", greeting);
   
   // Make the greeting more cheerful!
   strcat(greeting, " Happy Coding!!!");
   
   printf("New greeting: %s\n", greeting);
   
   // Let's make each word of the greeting capitalized
   char *token = strtok(greeting, " ");
   while (token != NULL) {
      token[0] = toupper(token[0]);
      token = strtok(NULL, " ");
   }
   
   printf("Capitalized greeting: %s\n", greeting);
   
   // Reversing the greeting
   int len = strlen(greeting);
   char reverse[len+1];
   for (int i = 0; i < len; i++) {
      reverse[i] = greeting[len-i-1];
   }
   reverse[len] = '\0';
   
   printf("Reversed greeting: %s\n", reverse);
   
   // Let's count the vowels in the greeting
   int vowels = 0;
   for (int i = 0; i < len; i++) {
      if (greeting[i] == 'a' || greeting[i] == 'e' || greeting[i] == 'i' || greeting[i] == 'o' || greeting[i] == 'u' || greeting[i] == 'A' || greeting[i] == 'E' || greeting[i] == 'I' || greeting[i] == 'O' || greeting[i] == 'U') {
         vowels++;
      }
   }
   
   printf("Number of vowels in the greeting: %d\n", vowels);
   
   // Let's make the greeting a bit shorter
   if (len > 20) {
      greeting[20] = '\0';
      strcat(greeting, "...");
   }
   
   printf("Shortened greeting: %s\n", greeting);
   
   return 0;
}