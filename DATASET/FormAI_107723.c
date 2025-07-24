//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sanitizeURL(char *url){
  char *sanitized = malloc(sizeof(char) * (strlen(url) + 1));
  char *sanitized_ptr = sanitized;
  
  while(*url){
    if(*url == ':' && *(url + 1) == '/' && *(url + 2) == '/'){
      strcpy(sanitized_ptr, "http://");
      sanitized_ptr += 7;
      url += 3;
    }
    else if(*url == '<' || *url == '>' || *url == '\'' || *url == '\"'){
      url += 1;
    }
    else{
      *sanitized_ptr++ = *url++;
    }
  }
  
  *sanitized_ptr = '\0';
  strcpy(url, sanitized);
  free(sanitized);
  return;
}

int main(){
  char url[100] = "http://www.<your-malicious-link-here>.com";
  printf("Original URL: %s\n", url);
  
  sanitizeURL(url);
  
  printf("Sanitized URL: %s\n", url);
  
  return 0;
}