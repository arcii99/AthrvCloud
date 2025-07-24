//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to sanitize URLs
char* sanitize_url(char* url) {
  int length = strlen(url); // Get the length of the URL
  char* new_url = (char*)malloc(length + 1); // Allocate memory for the sanitized URL
  int i, j;
  
  // Copy the original URL into the new URL string
  for (i = 0, j = 0; i < length; i++, j++) {
    // Replace backslash characters with forward slashes
    if (url[i] == '\\') {
      new_url[j] = '/';
    }
    // Remove any extraneous whitespace
    else if (isspace(url[i])) {
      j--;
    }
    else {
      new_url[j] = url[i];
    }
  }
  
  new_url[j] = '\0'; // Add null terminator to the end of the new URL string
  
  return new_url; // Return the sanitized URL
}

int main(void) {
  char url[1000];
  
  printf("Enter a URL to be sanitized: ");
  fgets(url, 1000, stdin);
  url[strcspn(url, "\n")] = '\0'; // Remove newline character from input
  
  char* sanitized_url = sanitize_url(url); // Sanitize the URL
  
  printf("Sanitized URL: %s\n", sanitized_url); // Display the sanitized URL
  
  free(sanitized_url); // Free allocated memory
  
  return 0;
}