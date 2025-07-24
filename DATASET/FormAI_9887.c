//FormAI DATASET v1.0 Category: Word Count Tool ; Style: Cryptic
#include <stdio.h>
#include <string.h>

int main()
{
   char str[1000];
   int count = 0, letter = 0, word = 0, space = 0, i;

   printf("Enter a sentence: ");
   gets(str);

  for(i=0;str[i]!='\0';i++)
   {
      if(str[i]>='a' && str[i]<='z' || str[i]>='A' && str[i]<='Z')
      {
          letter++;
      }
      else
      {
          space++;
      }
   }

   for(i=0;str[i]!='\0';i++)
   {
      if(str[i]==' ' && str[i-1]!=' ')
      {
          word++;
      }
      else if(str[i]=='\n' || str[i]=='\t' || str[i]=='\b')
      {
          continue;
      }
   }

   if(str[strlen(str)-1]!=' ')
   {
      word++;
   }
   count = letter - space;

   printf("\n");
   printf("The number of letters in the sentence: %d\n", count);
   printf("The number of words in the sentence: %d\n", word);
   
   return 0;
}