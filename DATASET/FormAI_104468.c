//FormAI DATASET v1.0 Category: String manipulation ; Style: Linus Torvalds
#include <stdio.h>
#include <string.h>

int main() 
{
   char str1[20] = "Hello";
   char str2[20] = "World";
   char str3[40];
   
   printf("Length of str1: %d\n", strlen(str1));
   
   strcpy(str3, str1); 
   printf("strcpy(str3, str1): %s\n", str3);
   
   strcat(str1, str2);    
   printf("strcat(str1, str2): %s\n", str1);
   
   printf("strcmp(str1, str2): %d\n", strcmp(str1, str2));
   printf("strcmp(str1, \"Helloworld\"): %d\n", strcmp(str1, "Helloworld"));

   for (int i = 0; str1[i] != '\0'; ++i) 
   {
      printf("%c ", str1[i]);
   }
   
   printf("\n");
   
   return 0;
}