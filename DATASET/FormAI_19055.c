//FormAI DATASET v1.0 Category: String manipulation ; Style: creative
#include <stdio.h>
#include <string.h>

int main() {
   char str1[100] = "Hello";
   char str2[100] = "World";
   char temp[100];

   printf("Original strings: \n");
   printf("String 1: %s\n", str1);
   printf("String 2: %s\n", str2);

   // Concatenating two strings by swapping them
   strcpy(temp, str1);
   strcpy(str1, str2);
   strcpy(str2, temp);

   printf("\nAfter swapping:\n");
   printf("String 1: %s\n", str1);
   printf("String 2: %s\n", str2);

   // Removing vowels from the first string
   int i, j;
   for(i = 0; str1[i] != '\0'; ++i)
   {
      while(!(str1[i] == 'a' || str1[i] == 'e' || str1[i] == 'i' ||
            str1[i] == 'o' || str1[i] == 'u' || str1[i] == 'A' ||
            str1[i] == 'E' || str1[i] == 'I' || str1[i] == 'O' ||
            str1[i] == 'U'))
      {
         for(j = i; str1[j] != '\0'; ++j)
         {
            str1[j] = str1[j + 1];
         }
         str1[j] = '\0';
      }
   }

   printf("\nString 1 after removing vowels: %s\n", str1);

   // Reversing the second string
   int len = strlen(str2);
   int k;
   for(k = 0; k < len / 2; ++k)
   {
      temp[k] = str2[k];
      str2[k] = str2[len - k - 1];
      str2[len - k - 1] = temp[k];
   }

   printf("\nString 2 after reversing: %s\n", str2);

   // Finding and replacing a substring in the first string
   char find[10], replace[10];
   printf("\nEnter a substring to find in String 1: ");
   scanf("%s", find);
   printf("Enter a string to replace the found substring: ");
   scanf("%s", replace);

   char *pos = strstr(str1, find);
   if(pos != NULL)
   {
      int index = pos - str1;
      int replace_len = strlen(replace);
      int find_len = strlen(find);
      if(replace_len == find_len)
      {
         strncpy(&str1[index], replace, replace_len);
      }
      else if(replace_len < find_len){
         memmove(&str1[index + replace_len], &str1[index + find_len], strlen(&str1[index + find_len]) + 1);
         strncpy(&str1[index], replace, replace_len);
      }
      else{
         int diff = replace_len - find_len;
         memmove(&str1[index + diff], &str1[index + find_len], strlen(&str1[index + find_len]) + 1);
         strncpy(&str1[index], replace, replace_len);
      }
      printf("\nString 1 after replacing '%s': %s\n", find, str1);
   }
   else{
      printf("\nSubstring not found in the String 1.");
   }

   return 0;
}