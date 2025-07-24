//FormAI DATASET v1.0 Category: Syntax parsing ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

int main()
{
   char *text = "(4+3)*2";
   int a, b, c;

   if (sscanf(text, "(%d+%d)*%d", &a, &b, &c) == 3)
   {
       int result = (a + b) * c;
       printf("%s = %d", text, result);
   }
   else
   {
       printf("%s is an invalid input", text);
   }

   return 0;
}