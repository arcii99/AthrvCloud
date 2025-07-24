//FormAI DATASET v1.0 Category: String manipulation ; Style: funny
#include <stdio.h>
#include <string.h>

int main() {
   char str1[20] = "Hello";
   char str2[20] = "World";
   char temp[20];

   printf("Original Strings:\n");
   printf("str1 = %s\n", str1);
   printf("str2 = %s\n\n", str2);

   // Swap the Strings
   strcpy(temp, str1);
   strcpy(str1, str2);
   strcpy(str2, temp);

   printf("After Swapping:\n");
   printf("str1 = %s\n", str1);
   printf("str2 = %s\n", str2);

   // Reverse the Strings
   printf("\nLet's reverse the strings too!\n");

   char temp1;
   int i, j;
   for(i=0, j=strlen(str1)-1; i<j; i++, j--){
      temp1 = str1[i];
      str1[i] = str1[j];
      str1[j] = temp1;
   }

   for(i=0, j=strlen(str2)-1; i<j; i++, j--){
      temp1 = str2[i];
      str2[i] = str2[j];
      str2[j] = temp1;
   }

   printf("After Reversing:\n");
   printf("str1 = %s\n", str1);
   printf("str2 = %s\n\n", str2);

   // Concatenate the Strings
   printf("Hey, let's add these strings together!\n");

   strcat(str1, str2);

   printf("After Concatenating:\n");
   printf("str1 = %s\n", str1);

   return 0;
}