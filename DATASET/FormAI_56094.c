//FormAI DATASET v1.0 Category: Searching algorithm ; Style: funny
#include <stdio.h>

int funnySearch(int arr[], int n, int x) 
{
   int i;
   printf("Let's search for %d...starting from the beginning...hmm..where is it?\n", x);
   for (i = 0; i < n; i++) 
   {
      printf("Nope, not here at index %d\n", i);
      if (arr[i] == x)
      {
         printf("Found it at index %d! Woohoo!\n", i);
         return i;
      }
   }
   printf("Couldn't find %d. Sorry pal.\n", x);
   return -1;
}

int main() 
{
   printf("Welcome to the Search Party! Our search algorithm is one of a kind.\n");
   int arr[] = {2, 4, 1, 5, 3, 7, 9, 8, 6, 10};
   int n = sizeof(arr)/sizeof(arr[0]);
   int x = 7;
   printf("Alright folks, let's search for %d....\n", x);
   int result = funnySearch(arr, n, x);
   (result == -1) ? printf("Sorry, but we couldn't find what you were looking for.\n") : printf("Woohoo! We found it at index %d!\n", result);

   return 0;
}