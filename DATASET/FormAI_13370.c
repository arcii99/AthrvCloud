//FormAI DATASET v1.0 Category: Log analysis ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char log_contents[1000], *line, *token, *message;
  int count = 0, i;
  FILE *log_file;

  log_file = fopen("example_log.txt", "r");

  if (log_file == NULL) {
    printf("Error opening log file\n");
    exit(1);
  }

  while(fgets(log_contents, 1000, log_file) != NULL) {
    line = strstr(log_contents, "ERROR");

    if (line != NULL) {
      count++;
      printf("Error %d: ", count);

      while(*line != '[') {
        printf("%c", *line);
        line++;
      }

      printf("\n");

      token = strtok(line, "]");

      while( token != NULL ) {
        printf( " %s\n", token );
        token = strtok(NULL, "]");
      }

      message = strstr(log_contents, "MESSAGE");

      if (message != NULL) {
        printf("Message: ");

        while(*message != '\0') {
          printf("%c", *message);
          message++;
        }

        printf("\n");
      }

      printf("\n");
    }
  }

  fclose(log_file);
  return 0;
}