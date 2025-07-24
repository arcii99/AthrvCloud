//FormAI DATASET v1.0 Category: Word Count Tool ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>

int main() {
   char str[1000], ch;
   int count = 0;

   printf("Enter some text: ");
   fgets(str, sizeof(str), stdin);

   printf("\nEnter a character to count: ");
   scanf("%c", &ch);

   for(int i = 0; i < strlen(str); i++) {
      if(str[i] == ch) {
         count++;
      }
   }

   printf("\n");
   printf("Total character count of '%c' in the given text is: %d", ch, count);
   printf("\n");

   return 0;
}