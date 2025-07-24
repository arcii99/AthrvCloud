//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  printf("Sherlock Holmes here! Let's investigate a CSV file.\n");

  FILE *csv_file = fopen("data.csv", "r");
  if (csv_file == NULL) {
    printf("Sorry, couldn't find the file. Case closed.\n");
    return 1;
  }

  char line[1024];

  printf("Looking for suspects in the CSV...\n");
  while (fgets(line, 1024, csv_file)) {
    char *token;
    token = strtok(line, ",");
    while (token != NULL) {
      printf("%s", token);
      token = strtok(NULL, ",");
    }
    printf("\n");
  }

  fclose(csv_file);

  printf("Case solved! The suspects' information has been extracted.\n");
  return 0;
}