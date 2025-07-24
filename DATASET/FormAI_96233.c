//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: intelligent
#include<stdio.h>
#include<string.h>
#define MAX_SIZE 100 /* maximum size of string */

int is_palindrome(char str[]);

int main()
{
   char str[MAX_SIZE];
   printf("Enter the string: ");
   gets(str);
   if(is_palindrome(str))
      printf("%s is palindrome.",str);
   else
      printf("%s is not palindrome.",str);
   return 0;
}

int is_palindrome(char str[])
{
   int i, len, flag;
   flag = 0;
   len = strlen(str);

   for(i=0;i < len ;i++){
      if(str[i] != str[len-i-1]){
         flag = 1;
         break;
      }
   }

   if (flag)
      return 0;
   else
      return 1;
}