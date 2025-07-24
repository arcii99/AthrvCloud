//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: optimized
#include <stdio.h>
#include <ctype.h>
#include <string.h>

void strip(char *str) {
   int i, j;
   for (i = j = 0; str[i]; i++)
      if (isalnum(str[i]))
         str[j++] = tolower(str[i]);
   str[j] = '\0';
}

int is_palindrome(char *str) {
   int len = strlen(str);
   for (int i = 0; i < len / 2; i++)
      if (str[i] != str[len - i - 1])
         return 0;
   return 1;
}

int main() {
   char str[1001];
   printf("Enter a string to check if it is a palindrome: ");
   fgets(str, 1001, stdin);
   strip(str);
   if (is_palindrome(str))
      printf("%s is a palindrome.\n", str);
   else
      printf("%s is not a palindrome.\n", str);
   return 0;
}