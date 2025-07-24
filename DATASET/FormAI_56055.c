//FormAI DATASET v1.0 Category: Syntax parsing ; Style: synchronous
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LEN 100

char* parse(char* input) {
  int n = strlen(input);
  int i = 0, j = 0;
  char buffer[MAX_LEN];
  int buffer_len = 0;
  int in_string = 0;

  for(i=0; i<n; i++) {
    if(input[i] == '"' && (i==0 || input[i-1] != '\\')) {
      in_string = !in_string;
    }

    if(input[i] == ' ' && !in_string) {
      buffer[buffer_len++] = '\n';
    } else {
      buffer[buffer_len++] = input[i];
    }
  }

  if(in_string) {
    fprintf(stderr, "Error: Unterminated string constant.\n");
    exit(1);
  }

  buffer[buffer_len] = '\0';
  return strdup(buffer);
}

int main() {
  char input[MAX_LEN];
  char *output;

  printf("Enter some C code:\n");
  fgets(input, MAX_LEN, stdin);

  output = parse(input);

  printf("\nThe parsed code is:\n");
  printf("%s\n", output);

  free(output);
  return 0;
}