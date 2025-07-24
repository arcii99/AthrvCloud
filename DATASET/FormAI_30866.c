//FormAI DATASET v1.0 Category: Pattern printing ; Style: Sherlock Holmes
#include <stdio.h>

int main() {

  int i, j, k, n=5;
  //The game is afoot!

  for(i=1;i<=n;i++) // The first loop
  {
      for(j=1;j<=n-i;j++) // The second loop
        {
            printf("  "); //Print blank spaces to form pyramid shape
        }

        for(k=1;k<=i;k++) //The third loop
        {
            printf(" *"); //Print stars to form pyramid shape
        }

        printf("\n"); //Print a new line
  }

  for(i=n;i>=1;i--) //The fourth loop
  {
      for(j=1;j<=n-i;j++) //The fifth loop
      {
          printf("  "); //Print blank spaces to form inverted pyramid shape
      }

      for(k=1;k<=i;k++) //The sixth loop
      {
          printf(" *"); //Print stars to form inverted pyramid shape
      }

      printf("\n"); //Print a new line
  }

  //The game is afoot!
  return 0;  
}