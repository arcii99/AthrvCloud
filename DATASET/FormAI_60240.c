//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: Dennis Ritchie
#include<stdio.h>
#include<string.h>

// function to sanitize the given URL string
void sanitize_url(char url[]) {
  int length = strlen(url);
  char temp[length];
  int j = 0;

  // loop through the characters of the URL string
  for(int i = 0; i < length; i++) {
    // if the current character is an alphabet or digit, add it to the temporary string
    if((url[i] >= 'a' && url[i] <= 'z') || (url[i] >= 'A' && url[i] <= 'Z') || (url[i] >= '0' && url[i] <= '9')) {
      temp[j++] = url[i];
    }
    // if the current character is '.', '-', or '?' add it to the temporary string
    if(url[i] == '.' || url[i] == '-' || url[i] == '?') {
      temp[j++] = url[i];
    }
  }

  // add null character to the end of the sanitized string
  temp[j] = '\0';

  // copy the sanitized string to the original URL string
  strncpy(url, temp, j);
}

// main function
int main() {
  char url[1000];

  // get the URL from the user
  printf("Enter the URL: ");
  scanf("%[^\n]", url);

  // sanitize the URL
  sanitize_url(url);

  // print the sanitized URL
  printf("Sanitized URL: %s\n", url);

  return 0;
}