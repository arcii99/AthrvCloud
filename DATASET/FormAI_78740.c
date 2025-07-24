//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: high level of detail
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void sanitize_url(char *url) {
   int i, j;
   char temp[strlen(url) + 1];
   for (i = 0, j = 0; i < strlen(url); i++) {
      if (isalnum(url[i]) || url[i] == ':' || url[i] == '/') {
         temp[j++] = url[i];
      }
   }
   temp[j] = '\0';
   strcpy(url, temp);
}

int main() {
   char url[200];
   printf("Enter the URL to sanitize: ");
   fgets(url, sizeof(url), stdin);
   if (strlen(url) > 0 && url[strlen(url) - 1] == '\n') {
      url[strlen(url) - 1] = '\0';
   }
   sanitize_url(url);
   printf("Sanitized URL: %s\n", url);
   return 0;
}