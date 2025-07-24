//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* sanitize_url(char* url) {
  char* temp = malloc(strlen(url) + 1);
  int j = 0;

  for (int i = 0; i < strlen(url); i++) {
    
    if (isalnum(url[i]) || url[i] == '.' || url[i] == '-' || url[i] == '_' || url[i] == '/') {
      temp[j] = url[i];
      j++;
    } 
    
    else if (isspace(url[i])) {
      temp[j] = '%';
      temp[j+1] = '2';
      temp[j+2] = '0';
      j += 3;
    }
  }
  
  temp[j] = '\0';
  return temp;
}

int main() {
  printf("Welcome to the futuristic URL sanitizer!\n");
  printf("Please enter a URL to sanitize: ");

  char* url = malloc(sizeof(char) * 500);
  scanf("%[^\n]s", url);

  char* sanitized_url = sanitize_url(url);

  printf("\nSanitized URL: %s\n", sanitized_url);

  free(url);
  free(sanitized_url);

  return 0;
}