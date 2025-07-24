//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 100

char* sanitize(char *url) {
      char *sanitized_url = calloc(MAX_INPUT_LENGTH, sizeof(char));
      char list_of_chars[] = {'.', '-', '_', '~', '/', '?', '=', '&'};
      int is_valid_char;
      int sanitized_url_index = 0;
     
      if (sanitized_url == NULL) {
           printf("Error: Memory allocation failed\n");
           exit(EXIT_FAILURE);
      }

      for (int i=0; i<strlen(url); i++) {
          is_valid_char = 0;

          if ((url[i] >= 'A' && url[i] <= 'Z') || (url[i] >= 'a' && url[i] <= 'z') || (url[i] >= '0' && url[i] <= '9')) {
              is_valid_char = 1;
          } else {
              for (int j=0; j<sizeof(list_of_chars)/sizeof(char); j++) {
                   if (url[i] == list_of_chars[j]) {
                       is_valid_char = 1;
                       break;
                   }
              }
          }

          if (is_valid_char) {
              sanitized_url[sanitized_url_index] = url[i];
              sanitized_url_index++;
          }
      }
      return sanitized_url;
}

int main(void) {
     char input_url[MAX_INPUT_LENGTH];
     char *sanitized_url;

     printf("Enter the URL to be sanitized up to %d chars: ", MAX_INPUT_LENGTH);
     fgets(input_url, MAX_INPUT_LENGTH, stdin);
     input_url[strcspn(input_url, "\n")] = '\0';

     sanitized_url = sanitize(input_url);

     printf("Sanitized URL: %s\n", sanitized_url);

     free(sanitized_url);

     return 0;
}