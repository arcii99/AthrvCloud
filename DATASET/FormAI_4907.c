//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: shape shifting
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 4096

const char *sanitize(const char *input){
  char buffer[MAX_LENGTH];
  size_t len, i, j;

  if(!input) {
    return NULL;
  }

  len = strlen(input);
  if (len > MAX_LENGTH) {
    return NULL;
  }
  for(i = 0, j = 0; i < len; i++){
    if (isalnum(input[i]) || isspace(input[i])){
      buffer[j++] = input[i];
    }
  }
  buffer[j] = '\0';
  return strdup(buffer);
}

int main(int argc, char **argv){
  char *input;

  printf("\nEnter the string to sanitize: ");
  if (fgets(input, MAX_LENGTH, stdin) == NULL){
    perror("An error occured while reading user input");
  }else {
    printf("\nOriginal String: %s", input);
    printf("\nSanitized String: %s", sanitize(input));
  }
  return 0;
}