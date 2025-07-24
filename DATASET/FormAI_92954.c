//FormAI DATASET v1.0 Category: String manipulation ; Style: peaceful
#include <stdio.h>
#include <string.h>

int main() {
   char str1[50], str2[50], temp[50];
   int i,j;

   printf("Enter the first string: ");
   scanf("%s",str1);

   printf("Enter the second string: ");
   scanf("%s",str2);

   // Concatenate the two strings
   strcat(str1, str2);
   printf("Concatenated string: %s\n", str1);

   // Reverse the string
   for(i=0; i<(strlen(str1)/2); i++) {
      temp[i] = str1[i];
      str1[i] = str1[strlen(str1)-i-1];
      str1[strlen(str1)-i-1] = temp[i];
   }
   printf("Reversed string: %s\n",str1);

   // Convert all upper case characters to lower case and vice versa
   for(i=0; str1[i]!='\0'; i++) {
      if(str1[i]>='A' && str1[i]<='Z') {
         str1[i] = str1[i] + 32;
      }
      else if(str1[i]>='a' && str1[i]<='z') {
         str1[i] = str1[i] - 32;
      }
   }
   printf("String with converted characters: %s\n", str1);

   // Remove all vowels
   for(i=0; str1[i]!='\0'; i++) {
      while(str1[i]=='a' || str1[i]=='e' || str1[i]=='i' || str1[i]=='o' || str1[i]=='u' || str1[i]=='A' || str1[i]=='E' || str1[i]=='I' || str1[i]=='O' || str1[i]=='U') {
         for(j=i; str1[j]!='\0'; j++) {
            str1[j] = str1[j+1];
         }
         str1[j] = '\0';
      }
   }
   printf("String with removed vowels: %s\n", str1);

   return 0;
}