//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: genious
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_URL_LENGTH 255

// Function to check if a character is alphanumeric or not
bool is_alphanumeric(char c) {
  return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
}

// Function to sanitize a URL
void sanitize_url(char *url) {
  char sanitized_url[MAX_URL_LENGTH];
  int j = 0;
  for (int i = 0; i < strlen(url); i++) {
    if (is_alphanumeric(url[i]) || url[i] == '.' || url[i] == '/' || url[i] == '-') {
      sanitized_url[j++] = url[i];
    } else if (url[i] == ' ') {
      sanitized_url[j++] = '_';
    }
  }
  sanitized_url[j] = '\0';
  strcpy(url, sanitized_url);
}

int main() {

  char url1[MAX_URL_LENGTH] = "https://www.example.com/This: is_an-example)URL#1";
  char url2[MAX_URL_LENGTH] = "https://www.example.com/This is an example URL 2";

  // Sanitize URL 1
  sanitize_url(url1);

  // Sanitize URL 2
  sanitize_url(url2);

  printf("Sanitized URL 1: %s\n", url1);
  printf("Sanitized URL 2: %s\n", url2);

  return 0;
}