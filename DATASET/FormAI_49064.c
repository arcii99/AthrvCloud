//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: Linus Torvalds
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool checkValidURL(char url[]) {
  bool valid = true; 

  // Check if URL starts with http:// or https://
  if (strncmp(url, "http://", 7) != 0 && strncmp(url, "https://", 8) != 0) {
    valid = false;
  }
  
  // Check if there are no spaces in the URL
  for (int i = 0; i < strlen(url); i++) {
    if (url[i] == ' ') {
      valid = false;
      break;
    }
  }

  // Check if URL has a top-level domain (com, org, etc.)
  int lastDotIndex = -1;
  for (int i = strlen(url) - 1; i >= 0; i--) {
    if (url[i] == '.') {
      lastDotIndex = i;
      break;
    }
  }
  if (lastDotIndex == -1 || lastDotIndex < strlen(url) - 4) {
    valid = false;
  }
  
  return valid;
}

int main() {
  char url[100];
  printf("Enter a URL: \n");
  scanf("%s", url);
  
  if (checkValidURL(url)) {
    printf("Valid URL.\n");
  } else {
    printf("Invalid URL.\n");
  }
  
  return 0;
}