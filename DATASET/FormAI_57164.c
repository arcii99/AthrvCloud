//FormAI DATASET v1.0 Category: Pattern printing ; Style: systematic
#include <stdio.h>
#include <string.h>

int main() {
   int i, j, n;
   char input_char = 'A'; // starting character of the pattern, can be changed
   char alphabet[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M',
                        'N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

   printf("Enter the number of rows you want in the pattern:\n");
   scanf("%d", &n);

   for(i=1; i<=n; i++) {
      for(j=1; j<=n-i; j++) {
         printf(" "); //print spaces before the first character of each row
      }
      for(j=1; j<=i; j++) {
         printf("%c ", input_char); // print the characters of that row
         input_char = (input_char == 'Z') ? 'A' : input_char+1; // increment the character as per the alphabet array
      }
      printf("\n");
   }

   return 0;
}