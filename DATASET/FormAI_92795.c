//FormAI DATASET v1.0 Category: String manipulation ; Style: accurate
#include <stdio.h>
#include <string.h>

int main() {
   char str1[50], str2[50];
   int i, j;

   printf("Enter first string: ");
   scanf("%s",str1);

   printf("Enter second string: ");
   scanf("%s",str2);

   //finding length of str1
   int len1 = strlen(str1);

   //finding length of str2
   int len2 = strlen(str2);

   //reversing str1
   for(i=0;i<len1/2;i++) {
      char temp = str1[i];
      str1[i] = str1[len1-i-1];
      str1[len1-i-1] = temp;
   }

   //reversing str2
   for(i=0;i<len2/2;i++) {
      char temp = str2[i];
      str2[i] = str2[len2-i-1];
      str2[len2-i-1] = temp;
   }

   //concatenating both strings
   strcat(str1,str2);

   //reversing the concatenated string
   int len3 = strlen(str1);
   for(i=0;i<len3/2;i++) {
      char temp = str1[i];
      str1[i] = str1[len3-i-1];
      str1[len3-i-1] = temp;
   }

   //displaying the final string
   printf("Final String: %s",str1);

   return 0;
}