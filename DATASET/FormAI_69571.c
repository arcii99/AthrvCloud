//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* sanitize_url(char* url) {
  char* sanitized_url = malloc(strlen(url) + 1); // Allocate memory for a new string
  char* current_char = url;
  char* sanitized_char = sanitized_url;

  while (*current_char != '\0') {
    if (isalnum(*current_char) || *current_char == '/' || *current_char == '.' || *current_char == '-') {
      *sanitized_char++ = *current_char++; // Copy over alphanumeric characters and allowed symbols
    } else if (*current_char == '%') {
      char hex[3] = {0};
      strncpy(hex, current_char + 1, 2); // Get the two hexadecimal digits following the "%" symbol
      if (isxdigit(hex[0]) && isxdigit(hex[1])) { // Check if the hexadecimal digits are valid
        int decimal = strtol(hex, NULL, 16); // Convert the hexadecimal digits to a decimal value
        *sanitized_char++ = decimal; // Add the corresponding ASCII character to the sanitized string
        current_char += 3; // Skip over the three characters that make up the hex encoding
      } else {
        *sanitized_char++ = '%'; // If the hex encoding is invalid, add the "%" symbol to the sanitized string
        current_char++; // Skip over the "%" symbol
      }
    } else {
      current_char++; // Skip over invalid characters
    }
  }

  *sanitized_char = '\0'; // Append null character to the end of the sanitized string

  return sanitized_url;
}

int main() {
  char* url = "http://www.example.com?q=Hello%20World!&key=value#fragment";
  char* sanitized_url = sanitize_url(url);
  printf("Original URL: %s\n", url);
  printf("Sanitized URL: %s\n", sanitized_url);
  free(sanitized_url); // Free the memory allocated by the sanitize_url function
  return 0;
}