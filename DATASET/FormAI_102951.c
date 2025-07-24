//FormAI DATASET v1.0 Category: Syntax parsing ; Style: romantic
#include <stdio.h>

void reverse(char*);

int main()
{
   char str[100];

   printf("Enter a string: ");
   fgets(str, 100, stdin);

   reverse(str);

   printf("Reversed string is: %s\n", str);

   return 0;
}

void reverse(char *s)
{
   char *start, *end, temp;

   start = s;
   end = s + strlen(s) - 1;

   while (start < end)
   {
       temp = *start;
       *start = *end;
       *end = temp;

       start++;
       end--;
   }
}