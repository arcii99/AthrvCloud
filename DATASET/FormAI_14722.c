//FormAI DATASET v1.0 Category: String manipulation ; Style: Alan Touring
#include <stdio.h>
#include <string.h>
 
int main () {
   char str1[50] = "Hello";
   char str2[50] = "World";
   char new_str[100];
 
   // concatenate two strings
   strcat(new_str, str1);
   strcat(new_str, " ");
   strcat(new_str, str2);
   printf("Concatenated string is: %s\n", new_str);
 
   // copying a string
   char copy_str[50];
   strcpy(copy_str, str1);
   printf("Copied string is: %s\n", copy_str);
 
   // compare two strings
   int result = strcmp(str1, str2);
   if(result < 0) {
      printf("%s comes before %s\n", str1, str2);
   } else if(result > 0) {
      printf("%s comes after %s\n", str1, str2);
   } else {
      printf("%s is the same as %s\n", str1, str2);
   }
 
   // converting lowercase to uppercase
   char lower_str[50] = "hello world";
   char upper_str[50];

   for(int i = 0; lower_str[i] != '\0'; i++) {
      if(lower_str[i] >= 'a' && lower_str[i] <= 'z') {
         upper_str[i] = lower_str[i] - 32;
      } else {
         upper_str[i] = lower_str[i];
      }
   }

   printf("Original string: %s\n", lower_str);
   printf("Uppercase string: %s\n", upper_str);

   return 0;
}