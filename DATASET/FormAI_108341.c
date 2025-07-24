//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: detailed
#include<stdio.h>
#include<string.h>

void sanitize(char* url) {
  int i, j = 0;
  char temp[strlen(url)+1];
  for (i = 0; i < strlen(url)+1; i++) {
    if (url[i] == '&' || url[i] == '|' || url[i] == ';' || url[i] == '$' || url[i] == '%' || url[i] == '@') {
      temp[j++] = '_';
    } else {
      temp[j++] = url[i];
    }
  }
  strcpy(url, temp);
}

int main() {
  char url[100];
  printf("Enter a URL to sanitize: ");
  scanf("%s", url);
  sanitize(url);
  printf("Sanitized URL: %s\n", url);
  return 0;
}