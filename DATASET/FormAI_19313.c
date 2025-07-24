//FormAI DATASET v1.0 Category: Data validation ; Style: relaxed
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool contains(char *string, char target);

int main() {
   char email[50];
   bool valid = false;
   printf("Enter your email address: ");
   scanf("%s", email);
   // ensure there is '@' and '.'
   if (contains(email, '@') && contains(email, '.')) {
      // ensure '@' appears before '.'
      int at_index = strchr(email, '@') - email;
      int dot_index = strchr(email, '.') - email;
      if (at_index < dot_index) {
         // ensure domain is at least two characters
         if (strlen(email) - dot_index >= 2) {
            valid = true;
         }
      }
   }
   if (valid) {
      printf("Valid email address entered.\n");
   } else {
      printf("Invalid email address entered.\n");
   }
   return 0;
}

bool contains(char *string, char target) {
   // iterate over string
   while (*string) {
      if (*string == target) {
         return true;
      }
      string++;
   }
   return false;
}