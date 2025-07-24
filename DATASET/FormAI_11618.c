//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: Dennis Ritchie
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 1000

void sanitizeUrl(char *url){
  char sanitizedUrl[MAX_URL_LENGTH];
  int sanitizedUrlLength = 0;
  
  int i;
  for (i = 0; i < strlen(url); i++){
    if (isalpha(url[i]) || isdigit(url[i]) || url[i] == '.' || url[i] == '/' || url[i] == '-' || url[i] == '_'){
      sanitizedUrl[sanitizedUrlLength] = url[i];
      sanitizedUrlLength++;
    }
  }
  
  sanitizedUrl[sanitizedUrlLength] = '\0';
  
  printf("Original URL: %s\n", url);
  printf("Sanitized URL: %s\n", sanitizedUrl);
}

int main(){
  char url[MAX_URL_LENGTH];
  
  printf("Please enter a URL to sanitize:\n");
  scanf("%s", url);
  
  sanitizeUrl(url);
  
  return 0;
}