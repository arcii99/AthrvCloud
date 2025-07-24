//FormAI DATASET v1.0 Category: String manipulation ; Style: light-weight
#include <stdio.h>
#include <string.h>

int main() {
   char str1[20] = "Hello";
   char str2[20] = "World";
   char temp[20];

   // concatenate strings
   strcat(str1, str2);
   printf("Concatenated string: %s\n", str1);

   // copy string
   strcpy(temp, str1);
   printf("Copied string: %s\n", temp);

   // reverse string
   int len = strlen(str1);
   for(int i = 0; i < len/2; i++) {
       char c = str1[i];
       str1[i] = str1[len-i-1];
       str1[len-i-1] = c;
   }
   printf("Reversed string: %s\n", str1);

   // compare strings
   int cmp = strcmp(str1, temp);
   if(cmp == 0) {
       printf("Strings are equal\n");
   } else {
       printf("Strings are not equal\n");
   }

   // find substring
   char* substr = strstr(str1, "World");
   if(substr != NULL) {
       printf("Substring found at position: %d\n", substr - str1);
   } else {
       printf("Substring not found\n");
   }

   return 0;
}