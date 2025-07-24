//FormAI DATASET v1.0 Category: Text processing ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>

int main() {
   char str[1000];
   int vowels = 0, consonants = 0;

   printf("Enter a string: ");
   fgets(str, sizeof(str), stdin);

   for(int i = 0; i < strlen(str); i++) {
      if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || 
         str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U') {
         vowels++;
      }
      else if ((str[i] >= 'a'&& str[i] <= 'z') || (str[i] >= 'A'&& str[i] <= 'Z')) {
         consonants++;
      }
   }

   printf("Number of vowels in the string: %d\n", vowels);
   printf("Number of consonants in the string: %d\n", consonants);

   return 0;
}