//FormAI DATASET v1.0 Category: String manipulation ; Style: satisfied
#include <stdio.h>
#include <string.h>

int main() {
   // initialize a string
   char str[50] = "Hello World!";

   // print the original string
   printf("Original String: %s\n", str);

   // reverse the string
   int len = strlen(str);
   char temp;
   for (int i = 0; i < len/2; i++) {
       temp = str[i];
       str[i] = str[len-i-1];
       str[len-i-1] = temp;
   }

   // print the reversed string
   printf("Reversed String: %s\n", str);

   // convert all characters to upper case
   for (int i = 0; i < len; i++) {
       str[i] = toupper(str[i]);
   }

   // print the string in all upper case
   printf("String in All Upper Case: %s\n", str);

   // convert all characters to lower case
   for (int i = 0; i < len; i++) {
       str[i] = tolower(str[i]);
   }

   // print the string in all lower case
   printf("String in All Lower Case: %s\n", str);

   // capitalize the first letter of each word
   for (int i = 0; i < len; i++) {
       if (i == 0 || str[i-1] == ' ') {
           str[i] = toupper(str[i]);
       }
   }

   // print the string with capitalized first letters of each word
   printf("String with Capitalized First Letters of Each Word: %s\n", str);

   return 0;
}