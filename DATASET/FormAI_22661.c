//FormAI DATASET v1.0 Category: String manipulation ; Style: imaginative
#include <stdio.h>
#include <string.h>

int main() {
   char str1[] = "I love";
   char str2[] = " programming";
   char str3[] = ", especially in C.";

   printf("Before concatenation:\n");
   printf("str1: %s\n", str1);
   printf("str2: %s\n", str2);
   printf("str3: %s\n", str3);

   int len1 = strlen(str1);
   int len2 = strlen(str2);
   int total_len = len1 + len2 + strlen(str3);

   char str4[total_len + 1];

   for (int i = 0; i < total_len; i++) {
      if (i < len1) {
         str4[i] = str1[i];
      } else if (i >= len1 && i < len1 + len2) {
         str4[i] = str2[i - len1];
      } else {
         str4[i] = str3[i - len1 - len2];
      }
   }

   str4[total_len] = '\0';

   printf("After concatenation:\n");
   printf("str4: %s\n", str4);
   return 0;
}