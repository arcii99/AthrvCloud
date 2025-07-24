//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: surrealist
/* Welcome to the URL Sanitizer program! This code will clean up any messy URLs you throw its way, with a touch of surrealism thrown in for good measure. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_URL_LENGTH 100

int main() {
  char url[MAX_URL_LENGTH];
  printf("Enter a messy URL that needs cleaning:\n");
  fgets(url, sizeof(url), stdin);
  url[strcspn(url, "\n")] = 0; // remove newline character
  
  if (strstr(url, "http") == NULL) {
    printf("This URL doesn't start with http! Adding it now...\n");
    strcat(url, "http://");
  }
  
  int url_length = strlen(url);
  int i, j = 0;
  char cleaned_url[MAX_URL_LENGTH];
  
  for (i = 0; i < url_length; i++) {
    if (url[i] == ':') {
      cleaned_url[j++] = url[i];
      cleaned_url[j++] = '/';
      cleaned_url[j++] = '/';
    } else if (url[i] == ' ') {
      printf("Oops, looks like your URL has some spaces in it. Replacing with \"%20\"...\n");
      cleaned_url[j++] = '%';
      cleaned_url[j++] = '2';
      cleaned_url[j++] = '0';
    } else if (url[i] == '.') {
      printf("Whoa, this URL is getting trippy. Swapping out periods for exclamation points...\n");
      cleaned_url[j++] = '!';
    } else if (url[i] == '/') {
      printf("Making a clean cut here...\n");
      cleaned_url[j++] = url[i];
    } else if (url[i] >= 'a' && url[i] <= 'z') {
      cleaned_url[j++] = url[i] - 32; // convert lowercase letters to uppercase
    } else {
      printf("This character \"%c\" is just too wild for me to handle. Replacing with \"*\"...\n", url[i]);
      cleaned_url[j++] = '*';
    }
  }
  
  cleaned_url[j] = '\0'; // terminate the string
  
  printf("\nHere's your cleaned up URL: %s\n", cleaned_url);
  
  return 0;
}