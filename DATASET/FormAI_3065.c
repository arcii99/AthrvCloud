//FormAI DATASET v1.0 Category: Log analysis ; Style: authentic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
  FILE *fp;
  char file_name[100], line[100], *token;
  int count = 0, line_count = 0;

  printf("Enter the name of the log file: ");
  scanf("%s", file_name);

  fp = fopen(file_name, "r");
  
  if(fp == NULL) {
    printf("Error opening file\n");
    return 0;
  }

  printf("\n\n------------Log Analysis------------\n\n");
  printf("Log file: %s\n\n", file_name);

  while (fgets(line, 100, fp)) {
    line_count++;

    printf("Line %d: %s", line_count, line);

    token = strtok(line, " ");

    while (token != NULL) {
      if (strstr(token, "ERROR") != NULL) {
        count++;
        printf("\n--> Error found in line %d\n\n", line_count);

        break;
      }
      token = strtok(NULL, " ");
    }
  }

  if (count == 0) printf("\nNo errors found in the log file.\n");
  else printf("\n%d errors found in the log file.\n", count);

  fclose(fp);

  return 0;
}