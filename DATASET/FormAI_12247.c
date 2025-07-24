//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>

// Function to remove all non-alphanumeric characters from a URL
void urlSanitizer(char* url) {
  for(int i = 0; i < strlen(url); i++) {
    if(!isalnum(url[i])) {
      url[i] = '-';
    }
  }
}

int main() {
  char url[100];
  printf("Enter a URL: ");
  scanf("%s", url);

  urlSanitizer(url);

  printf("Sanitized URL: %s", url);
  
  return 0;
}