//FormAI DATASET v1.0 Category: Log analysis ; Style: romantic
#include <stdio.h>

int main() {
  FILE *file = fopen("example.log", "r");
  if (file == NULL) {
    printf("Error: Unable to open file.\n");
    return 1;
  }
  
  char line[256];
  while (fgets(line, sizeof(line), file)) {
    printf("%s", line); // print each log line
  }
  
  fclose(file);
  return 0;
}