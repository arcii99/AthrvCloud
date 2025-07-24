//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: ultraprecise
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_URL_LENGTH 100

char* sanitizeUrl(char* url) {
  char sanitizedUrl[MAX_URL_LENGTH] = {'\0'};  // initialize all elements to null character
  int j = 0;
  for (int i = 0; i < strlen(url); i++) {
    if (url[i] == ' ') {
      sanitizedUrl[j] = '%';
      sanitizedUrl[j+1] = '2';
      sanitizedUrl[j+2] = '0';
      j += 3;
    } else {
      sanitizedUrl[j] = url[i];
      j++;
    }
  }
  sanitizedUrl[j] = '\0';
  char* result = (char*)malloc((strlen(sanitizedUrl)+1) * sizeof(char));  // allocate memory to safely return pointer
  strcpy(result, sanitizedUrl);
  return result;
}

int main() {
  char url[MAX_URL_LENGTH];
  printf("Enter URL to sanitize: ");
  fgets(url, MAX_URL_LENGTH, stdin);
  url[strcspn(url, "\n")] = '\0';  // remove newline character from input

  char* sanitizedUrl = sanitizeUrl(url);
  printf("Sanitized URL: %s", sanitizedUrl);

  free(sanitizedUrl);  // free allocated memory to prevent memory leaks
  return 0;
}