//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: complete
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char* sanitize_url(char* url) {
  // Remove leading/trailing white space
  char* trimmed_url = url;
  while (isspace(*trimmed_url)) {
    trimmed_url++;
  }
  char* end = trimmed_url + strlen(trimmed_url) - 1;
  while (end > trimmed_url && isspace(*end)) {
    end--;
  }
  *(end + 1) = '\0';

  // Remove query parameters
  char* question_mark = strchr(trimmed_url, '?');
  if (question_mark != NULL) {
    *question_mark = '\0';
  }

  // Remove protocol
  if (strncmp(trimmed_url, "http://", 7) == 0) {
    trimmed_url += 7;
  } else if (strncmp(trimmed_url, "https://", 8) == 0) {
    trimmed_url += 8;
  }

  // Remove trailing slash
  end = trimmed_url + strlen(trimmed_url) - 1;
  if (*end == '/') {
    *end = '\0';
  }

  // Return sanitized url
  return trimmed_url;
}

int main(void) {
  char url1[] = "  http://example.com/test/abcd/xyz/  ";
  char url2[] = "https://example.com?param=value";
  char url3[] = "http://example.com/test/";
  char url4[] = "example.com/";
  char url5[] = "http://example.com/   ";
  char url6[] = "example.com  ";
  char url7[] = "http://example.com/..";
  char url8[] = "  it is not a URL  ";

  printf("Sanitized URL: %s\n", sanitize_url(url1));
  printf("Sanitized URL: %s\n", sanitize_url(url2));
  printf("Sanitized URL: %s\n", sanitize_url(url3));
  printf("Sanitized URL: %s\n", sanitize_url(url4));
  printf("Sanitized URL: %s\n", sanitize_url(url5));
  printf("Sanitized URL: %s\n", sanitize_url(url6));
  printf("Sanitized URL: %s\n", sanitize_url(url7));
  printf("Sanitized URL: %s\n", sanitize_url(url8));

  return 0;
}