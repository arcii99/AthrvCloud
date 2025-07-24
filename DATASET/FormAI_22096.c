//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_URL_LENGTH 200

bool is_valid_url_char(char c) {
  // accept alphanumeric & a few special characters in URL
  return (c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z') ||
         (c >= 'a' && c <= 'z') || c == '.' || c == '/' || c == '_';
}

void sanitize_url(char *input_url, char *output_url) {
  int input_length = strlen(input_url);
  int output_length = 0;

  // loop through each character of input_url
  for (int i = 0; i < input_length; i++) {
    if (output_length == MAX_URL_LENGTH - 1)
      break;

    char c = input_url[i];

    if (!is_valid_url_char(c))
      continue;

    // convert uppercase characters to lowercase
    if (c >= 'A' && c <= 'Z')
      c += 32;

    output_url[output_length++] = c;
  }

  output_url[output_length] = '\0';
}

int main() {
  char input_url[MAX_URL_LENGTH], output_url[MAX_URL_LENGTH];

  printf("Enter URL to sanitize:\n");
  scanf("%s", input_url);

  sanitize_url(input_url, output_url);

  printf("Sanitized URL: %s\n", output_url);

  return 0;
}