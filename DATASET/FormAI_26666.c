//FormAI DATASET v1.0 Category: Data validation ; Style: brave
#include <stdio.h>
#include <ctype.h>

int main()
{
   char name[50];
   printf("Please enter your name: ");
   fgets(name, sizeof(name), stdin); // read user input including spaces
   int nameLength = strlen(name);
   int isValid = 1; // assume name is valid until proven otherwise
   
   for (int i = 0; i < nameLength; i++) {
        if (!isalpha(name[i]) && name[i] != ' ') { // check if character is not a letter or space
            isValid = 0;
            break; // exit loop if name is invalid
        }
   }
   
   if (isValid) {
        printf("Welcome %s", name);
   } else {
        printf("Invalid name. Please enter alphabetic characters only.");
  }

   return 0;
}