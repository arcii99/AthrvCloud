//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: surrealist
#include <stdio.h>

int main() {
  char input_url[100], output_url[100];
  int i, j = 0;

  printf("Enter the URL to sanitize: ");
  scanf("%s", input_url);

  for (i = 0; input_url[i] != '\0'; i++) {
    if (input_url[i] == 'c' && input_url[i+1] == 'a' && input_url[i+2] == 't') {
      output_url[j] = 'd';
      output_url[j+1] = 'o';
      output_url[j+2] = 'g';
      j += 3;
      i += 2;
      continue;
    }
    output_url[j] = input_url[i];
    j++;
  }

  output_url[j] = '\0';

  printf("\nSanitized URL: %s\n", output_url);

  return 0;
}