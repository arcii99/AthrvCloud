//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: distributed
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define MAX_URL_LENGTH 200

// Helper function to check if a character is a digit
bool isDigit(char c) {
  return (c >= '0' && c <= '9');
}

// Helper function to check if a character is an alphabetic character
bool isAlpha(char c) {
  return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

// Sanitizes a given URL by removing any non-alphanumeric characters
char* sanitizeURL(char* url) {
  int length = strlen(url);
  char* sanitized_url = (char*) malloc(MAX_URL_LENGTH * sizeof(char));
  int j = 0;
  for (int i = 0; i < length; i++) {
    char c = url[i];
    if (isDigit(c) || isAlpha(c)) {
      sanitized_url[j++] = c;
    }
  }
  sanitized_url[j] = '\0';
  return sanitized_url;
}

int main() {
  char* url = "https://www.example.com/path/to/page?query=string";
  char* sanitized_url = sanitizeURL(url);
  printf("Sanitized URL: %s\n", sanitized_url);
  free(sanitized_url);
  return 0;
}