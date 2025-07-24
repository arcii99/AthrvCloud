//FormAI DATASET v1.0 Category: String manipulation ; Style: shocked
#include <stdio.h>
#include <string.h>

int main() {
   char str1[30] = "C String Manipulation", str2[30];
   int len = strlen(str1);
   
   // Copying str1 to str2 in reverse order
   for(int i=0; i<len; i++){
       str2[i] = str1[len-i-1];
   }
   str2[len] = '\0';
   
   printf("Original string:\n%s\n", str1);
   printf("Reversed string:\n%s\n\n", str2);
   
   // Converting the string to uppercase
   for(int i=0; i<len; i++){
       if(str1[i] >= 'a' && str1[i] <= 'z'){
           str1[i] -= 32;
       }
   }
   
   printf("Uppercase string:\n%s\n\n", str1);
   
   // Replacing a substring in the string
   char substr[] = "Manipulation";
   char replace[] = "Operation";
   
   char* ptr = strstr(str1, substr);
   if(ptr){
       int index = ptr - str1;
       for(int i=0; i<strlen(replace); i++){
           str1[index+i] = replace[i];
       }
   }
   
   printf("Replaced string:\n%s\n\n", str1);
   
   // Removing leading and trailing spaces from the string
   char str3[] = "   Remove Spaces   ";
   char str4[30];
   
   int spaceStart = 0, spaceEnd = strlen(str3)-1;
   
   while(str3[spaceStart] == ' ') spaceStart++;
   while(str3[spaceEnd] == ' ') spaceEnd--;
   
   for(int i=0; i<=spaceEnd-spaceStart; i++){
       str4[i] = str3[spaceStart+i];
   }
   str4[spaceEnd-spaceStart+1] = '\0';
   
   printf("Original string:\n%s\n", str3);
   printf("Trimmed string:\n%s\n", str4);
   
   return 0;
}