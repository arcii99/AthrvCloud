//FormAI DATASET v1.0 Category: Word Count Tool ; Style: standalone
#include <stdio.h>
#include <string.h>

int main() {
   char str[1000], ch;
   int i, count = 0;

   printf("Enter a string: ");
   fgets(str, sizeof(str), stdin);

   printf("Enter a character to count: ");
   scanf("%c", &ch);

   for (i = 0; str[i] != '\0'; ++i) {
      if (ch == str[i])
         ++count;
   }

   printf("Frequency of %c = %d", ch, count);
   
   return 0;
}