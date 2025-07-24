//FormAI DATASET v1.0 Category: String manipulation ; Style: visionary
#include <stdio.h>
#include <string.h>

int main() {
   char str1[] = "Hello";
   char str2[] = "World!";
   char str3[6];

   // Copying the first 5 characters of str1 to str3
   strncpy(str3, str1, 5);
   
   // Concatenating str2 with str3 to create a new string
   strcat(str3, str2);
   
   // Reversing the new string
   int len = strlen(str3);
   char result[len];
   for(int i=0; i<len; i++){
     result[i] = str3[len-i-1];
   }
   
   // Printing the new string and its length
   printf("The result string is: %s\n", result);
   printf("The length of the result string is: %d\n", strlen(result));
   
   return 0;
}