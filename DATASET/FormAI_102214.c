//FormAI DATASET v1.0 Category: Recursive ; Style: energetic
#include <stdio.h>

void rabid_fibonacci(int n, int a, int b, int c)
{
   if(n == 0)
   {
      printf("%d\n", a);
   }
   else if(n == 1)
   {
      printf("%d\n", b);
   }
   else if(n == 2)
   {
      printf("%d\n", c);
   }
   else
   {
      printf("%d %d %d\n", a, b, c);
      rabid_fibonacci(n - 1, b, c, a + b + c);
   }
}

int main()
{
   int n;
   
   printf("Enter the number of terms to be printed: ");
   scanf("%d", &n);
   
   if(n >= 3)
   {
      printf("Starting the program... Fasten your seatbelts!\n");
   }
   else
   {
      printf("This program is not for wimps! Exiting now...\n");
      return 0;
   }
   
   rabid_fibonacci(n, 0, 1, 1);
   
   printf("Wohoo! All done! Exiting in 3, 2, 1...\n");
   
   return 0;
}