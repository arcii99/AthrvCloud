//FormAI DATASET v1.0 Category: Log analysis ; Style: shocked
#include <stdio.h>

int main() {

  FILE *log_file = NULL;
  char line[256];

  log_file = fopen("example_log.txt", "r");

  if (log_file == NULL) {
    printf("Failed to open log file!");
    return 1;
  }

  int num_200 = 0;
  int num_400 = 0;
  int num_500 = 0;

  while (fgets(line, sizeof(line), log_file)) {
    if (strstr(line, "200 OK")) {
      num_200++;
    } else if (strstr(line, "400 Bad Request")) {
      num_400++;
    } else if (strstr(line, "500 Internal Server Error")) {
      num_500++;
    }
  }

  printf("200 OK: %d\n", num_200);
  printf("400 Bad Request: %d\n", num_400);
  printf("500 Internal Server Error: %d\n", num_500);

  fclose(log_file);
  
  return 0;

}