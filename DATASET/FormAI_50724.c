//FormAI DATASET v1.0 Category: Log analysis ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

  int i; 
  char logfile[100];
  FILE *fp; 

  printf("Enter the path of the log file to be analyzed: ");
  scanf("%s",logfile);

  fp = fopen(logfile, "r");

  if (fp == NULL) {
    printf("Error opening file\n");
    exit(1);
  }

  char line[200], *str, *token;
  int count = 0;

  while (fgets(line, 200, fp)) {
    str = strstr(line, "ERROR");
    if (str != NULL) {
      count++;
      printf("Error occurred on line %d:",count);
      token = strtok(line, " ");
      while (token != NULL) {
        printf("%s ", token);
        token = strtok(NULL, " ");
      }
      printf("\n\n");
    }
  } 

  printf("Number of errors detected in %s: %d\n",logfile, count); 

  fclose(fp);

  return 0;
}