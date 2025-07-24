//FormAI DATASET v1.0 Category: Text processing ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
   char str[100], ch;
   int i, vowels = 0, consonants = 0, digits = 0, spaces = 0;

   printf("Enter a string: ");
   gets(str);

   for(i=0; str[i]!='\0'; i++) {
      ch = str[i];

      if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' || ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U') {
         vowels++;
      } else if((ch>='a'&& ch<='z') || (ch>='A'&& ch<='Z')) {
         consonants++;
      } else if(ch>='0' && ch<='9') {
         digits++;
      } else if (ch == ' ') {
         spaces++;
      }
   }

   printf("\n");
   printf("Number of vowels in the string: %d\n", vowels);
   printf("Number of consonants in the string: %d\n", consonants);
   printf("Number of digits in the string: %d\n", digits);
   printf("Number of spaces in the string: %d\n", spaces);
   
   return 0;
}