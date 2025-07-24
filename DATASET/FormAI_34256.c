//FormAI DATASET v1.0 Category: String manipulation ; Style: surrealist
#include <stdio.h>
#include <string.h>

int main() {
   char str1[20] = "The moon is made ";
   char str2[20] = "of cheese.";
   char str3[50];
   int i, j;

   /* Add some extra cheese */
   for(i = 0; i < strlen(str1); i++){
      str3[i] = str1[i];
   }
   for(j = 0; j < strlen(str2); j++){
      str3[i+j] = str2[j];
   }
   str3[i+j] = '\0';

   printf("Original string 1: %s\n", str1);
   printf("Original string 2: %s\n", str2);
   printf("Mixed string: %s\n\n", str3);

   /* Replace the word "cheese" with "unicorn tears" */
   char *ptr = strstr(str3, "cheese");
   if (ptr) {
      strncpy(ptr, "unicorn tears", strlen("unicorn tears"));
   }

   printf("Mixed string after transformation: %s\n\n", str3);

   /* Capitalize the first letter of each word */
   int k;
   for(k = 0; k < strlen(str3); k++) {
      if(k == 0 || str3[k-1] == ' ') {
         if(str3[k] >= 'a' && str3[k] <= 'z') {
            str3[k] -= 32;
         }
      }
   }

   printf("Mixed string after capitalization: %s\n\n", str3);

   /* Reverse the order of the words */
   char temp[50];
   int last_space = strlen(str3) - 1;
   for(k = strlen(str3) - 2; k >= 0; k--) {
      if(str3[k] == ' ') {
         strncpy(temp, &str3[k+1], last_space - k);
         temp[last_space - k] = ' ';
         temp[last_space - k + 1] = '\0';
         printf("%s", temp);
         last_space = k;
      }
   }
   strncpy(temp, str3, last_space);
   temp[last_space] = ' ';
   temp[last_space + 1] = '\0';
   printf("%s", temp);

   return 0;
}