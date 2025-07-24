//FormAI DATASET v1.0 Category: String manipulation ; Style: excited
#include <stdio.h>
#include <string.h>

int main() {

   char str1[20] = "Hello";
   char str2[20] = "World";
   char str3[20];
   int len ;

   // concatenate two strings
   strcat(str1, str2);
   printf("strcat(str1, str2) : %s\n", str1);

   // copy one string to another
   strcpy(str3, str1);
   printf("strcpy(str3, str1) : %s\n", str3);

   // string length
   len = strlen(str1);
   printf("strlen(str1) : %d\n", len);

   // search for a substring
   char* subStr = strstr(str1, "or");
   printf("strstr(str1, 'or') : %s\n", subStr);

   // convert to uppercase
   char upperStr[20];
   for(int i = 0; str1[i]!='\0'; i++){
      if(str1[i] >= 'a' && str1[i] <= 'z'){
         upperStr[i] = str1[i] - 32;
      }
      else{
         upperStr[i] = str1[i];
      }
   }
   printf("Uppercase Version : %s\n", upperStr);

   // convert to lowercase
   char lowerStr[20];
   for(int i = 0; str1[i]!='\0'; i++){
      if(str1[i] >= 'A' && str1[i] <= 'Z'){
         lowerStr[i] = str1[i] + 32;
      }
      else{
         lowerStr[i] = str1[i];
      }
   }
   printf("Lowercase Version : %s\n", lowerStr);

   return 0;
}