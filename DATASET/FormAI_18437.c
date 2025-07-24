//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Sur-realist C URL Sanitizer
int main(int argc, char *argv[]) {
  char* dirty_url;
  char* clean_url;
  
  dirty_url  = (char*) malloc(sizeof(char) * 1000);
  clean_url  = (char*) malloc(sizeof(char) * 1000);
  
  printf("Input a dirty URL: ");
  scanf("%s", dirty_url);
  
  int len = strlen(dirty_url);
  int j = 0;
  for (int i = 0; i < len + 1; i++) {
    if (dirty_url[i] == '.') {
      clean_url[j++] = '_';
    } 
    else if (dirty_url[i] == '/') {
      clean_url[j++] = '-';
    } 
    else if (dirty_url[i] != '?' && dirty_url[i] != '&' && dirty_url[i] != '=') {
      clean_url[j++] = dirty_url[i];
    }
  }

  printf("Clean URL: %s\n", clean_url);
  
  free(dirty_url);
  free(clean_url);
  
  return 0;
}