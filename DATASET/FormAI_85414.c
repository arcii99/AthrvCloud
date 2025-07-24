//FormAI DATASET v1.0 Category: Syntax parsing ; Style: happy
// Welcome to my happy C Syntax parsing program!
// This program will take a look at your code,
// And make sure that each line will hold!
// So if there are any errors, don't you fear!
// This program will make them all disappear!
// Let's get started with the code so dear:

#include <stdio.h>

int main() {
   char str[100];
   int i;

   printf("Enter a string of characters: ");
   scanf("%s", str);

   printf("Your string in uppercase is: ");
   for(i = 0; str[i]; i++) {
      putchar(toupper(str[i]));
   }

   return 0;
}

// This program will take a string from the user,
// And convert all the characters to uppercase.
// So when the user runs this program once,
// They can be sure their code won't be a dunce!
// This program's happy tone will make them smile,
// And they'll be sure to code in a good style!