//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: surprised
#include <stdio.h>
#include <string.h>

void sanitize(char* url) {
  char* bad_strings[4] = {"http://", "https://", "ftp://", "sftp://"}; //define an array of bad strings
  
  for (int i=0; i<4; i++) {
    if (strstr(url, bad_strings[i]) != NULL) { //if the bad string is found in the URL
      memmove(url, url+strlen(bad_strings[i]), 1+strlen(url+strlen(bad_strings[i]))); //remove bad string from URL
      i--; //check again to make sure all bad strings are removed
    }
  }
}

int main() {
  char url[100];
  printf("Enter a URL to sanitize: ");
  scanf("%s", url);
  
  printf("\nOriginal URL: %s\n", url);
  sanitize(url);
  printf("\nSanitized URL: %s\n", url);
  
  return 0;
}