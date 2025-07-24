//FormAI DATASET v1.0 Category: Error handling ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void error_handling(char *message) {
  fprintf(stderr, "Error: %s\n", message);
  exit(1);
}

int main(int argc, char *argv[]) {
  if(argc != 3) {
    error_handling("Invalid number of arguments");
  }

  FILE *fp;
  char *filename = argv[1];
  char *mode = argv[2];
  
  if(strcmp(mode, "r") != 0 && strcmp(mode, "w") != 0) {
    error_handling("Invalid file mode");
  }

  if((fp = fopen(filename, mode)) == NULL) {
    error_handling("Failed to open file");
  }

  char line[100];
  int line_num = 1;
  while(fgets(line, 100, fp) != NULL) {
    if(line[0] == '#') {
      continue;
    }
    int num = atoi(line);
    if(num == 0) {
      error_handling("Failed to convert string to integer");
    }
    printf("Line %d: %d\n", line_num, num);
    line_num++;
  }

  if(ferror(fp)) {
    error_handling("Error reading from file");
  }

  fclose(fp);
  return 0;
}