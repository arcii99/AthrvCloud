//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: romantic
#include <stdbool.h>  
#include <stdlib.h>  
#include <stdio.h>  
#include <string.h>  
char* sanitize_url(char* dirty_url) {  
  char* clean_url = malloc(strlen(dirty_url) + 1);  
  bool read_domain = false;  
  bool read_params = false;  
  int clean_index = 0;  
  for (int i = 0; i < strlen(dirty_url); i++) {  
    char c = dirty_url[i];  
    if (c == '?' || c == '#') {  
      read_params = true;  
      clean_url[clean_index++] = c;  
    } else if (c == '/' && !read_domain) {  
      read_domain = true;  
      clean_url[clean_index++] = c;  
    } else if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9') || c == ':' || c == '.' || c == '-') {  
      if (read_params) {  
        clean_url[clean_index++] = c;  
      } else {  
        clean_url[clean_index++] = tolower(c);  
      }  
    }  
  }  
  clean_url[clean_index] = '\0';  
  return clean_url;  
}  

int main() {  
  char* dirty_url = "https://www.BadDomain.com/?Are=you&feeling=dirty#OhYes";  
  char* sanitized_url = sanitize_url(dirty_url);  
  printf("%s\n", sanitized_url);  
  free(sanitized_url);  
}