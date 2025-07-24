//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>

int main() {
   char url[500];
   printf("Enter URL: ");
   scanf("%s", url);
   
   // replace any occurences of ' ' with '%20'
   for(int i=0;url[i]!='\0';i++) {
       if(url[i] == ' ') {
           strcpy(url+i+1,url+i+2);
           strcpy(url+i+1,"%20");
           i+=2;
       }
   }
   
   // remove any trailing '/'
   if(url[strlen(url)-1] == '/') url[strlen(url)-1] = '\0';
   
   // check if URL contains any cyberpunk keywords
   if(strstr(url, "hack") || strstr(url, "cyber") || strstr(url, "neon")) {
       printf("Error: Invalid URL contains forbidden keywords.\n");
       return 1;
   }
   
   printf("Sanitized URL: %s\n", url);
   
   return 0;
}