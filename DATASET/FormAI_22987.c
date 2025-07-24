//FormAI DATASET v1.0 Category: Text processing ; Style: peaceful
#include <stdio.h>
#include <string.h>

int main()
{
   char text[1000];
   int vowels = 0, consonants = 0, digits = 0, spaces = 0;

   printf("Enter a string: ");
   gets(text);

   for(int i = 0; i < strlen(text); i++) {
      if((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z')) {
         if(text[i] == 'a' || text[i] == 'e' || text[i] == 'i' || text[i] == 'o' || text[i] == 'u' || text[i] == 'A' || text[i] == 'E' || text[i] == 'I' || text[i] == 'O' || text[i] == 'U')
            vowels++;
         else
            consonants++;
      }
      else if(text[i] >= '0' && text[i] <= '9')
         digits++;
      else if(text[i] == ' ')
         spaces++;
   }

   printf("\nString information:\n");
   printf("Number of vowels: %d\n", vowels);
   printf("Number of consonants: %d\n", consonants);
   printf("Number of digits: %d\n", digits);
   printf("Number of spaces: %d\n", spaces);

   return 0;
}