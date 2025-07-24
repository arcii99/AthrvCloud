//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: real-life
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
   char url[1000], result[1000];
   int i, j=0, len;

   printf("Enter a URL to sanitize: ");
   scanf("%s", url);

   // Converting to lowercase
   for(i=0; url[i]; i++){
      url[i] = tolower(url[i]);
   }

   len = strlen(url);

   // Removing http:// or https://
   if(strstr(url, "http://")){
      j = 7;
   } else if(strstr(url, "https://")){
      j = 8;
   }

   // Sanitizing the URL
   for(i=j; i<len; i++){
      if(url[i] == ':' || url[i] == '/' || url[i] == '?' || url[i] == '#' || url[i] == '[' || url[i] == ']' || url[i] == '@' || url[i] == '!' || url[i] == '$' || url[i] == '&' || url[i] == '\'' || url[i] == '(' || url[i] == ')' || url[i] == '*' || url[i] == '+' || url[i] == ',' || url[i] == ';' || url[i] == '=' || url[i] == '_' || url[i] == '~' || url[i] == '.' || url[i] == '%'){
         result[i-j] = url[i];
      } else {
         result[i-j] = '_';
      }
   }
   result[i-j] = '\0';

   printf("Sanitized URL: %s", result);
   return 0;
}