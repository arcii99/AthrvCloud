//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLS 20
#define MAX_INPUT 1000

int main() {
  char line[MAX_INPUT];
  char* values[MAX_COLS];
  int num_values;

  printf("Welcome to the happy CSV reader program!\n");
  printf("Please enter a CSV file:\n");
  
  while (fgets(line, MAX_INPUT, stdin)) {
    printf("Reading in: %s", line);
    num_values = 0;

    char* token;
    token = strtok(line, ",");
    
    while (token && num_values < MAX_COLS) {
      values[num_values] = malloc(sizeof(token));
      strcpy(values[num_values], token);
      num_values++;
      
      token = strtok(NULL, ",");
    }
    
    printf("Parsed %d values:\n", num_values);
    for (int i = 0; i < num_values; i++) {
      printf("%d: %s\n", i, values[i]);
      free(values[i]);
    }
    
    printf("Please enter another CSV file (or enter CTRL-D to quit):\n");
  }

  printf("Thanks for using the happy CSV reader!\n");
  
  return 0;
}