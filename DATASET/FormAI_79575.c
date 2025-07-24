//FormAI DATASET v1.0 Category: String manipulation ; Style: detailed
#include<stdio.h>
#include<string.h> // To use string functions
 
int main() {
   char str1[20] = "Hello";
   char str2[20] = ", World!";
   
   printf("Original string 1: %s\n", str1); // Prints the original string 1
   printf("Original string 2: %s\n", str2); // Prints the original string 2
   
   // Concatenating two strings using strcat
   strcat(str1, str2);
   printf("Concatenated string: %s\n", str1); // Prints the concatenated string
   
   // Copying string using strcpy 
   char str3[20];
   strcpy(str3, str1);
   printf("Copied string: %s\n", str3); // Prints the copied string
   
   // Comparing two strings using strcmp
   char str4[20] = "Hello, World!";
   int compVal = strcmp(str4, str1);
   if(compVal == 0) 
      printf("The strings are same.\n"); // If zero is returned by strcmp, the strings are same
   else {
      printf("The strings are not same.\n"); // Otherwise, the strings are not same
   }
   
   // Reversing a string 
   char str5[20] = "Hello, World!";
   int i, j;
   char temp;
   for(i = 0, j = strlen(str5) - 1; i < j; i++, j--) {
      temp = str5[i];
      str5[i] = str5[j];
      str5[j] = temp;
   }
   printf("Reversed string: %s\n", str5); // Prints the reversed string
   
   return 0;
}