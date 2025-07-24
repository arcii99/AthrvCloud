//FormAI DATASET v1.0 Category: Log analysis ; Style: configurable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char *argv[]) {
  char *logFile = argv[1];
  char *pattern = argv[2];
  char *outputFile = argv[3];
  
  FILE *fp = fopen(logFile, "r");
  if(fp == NULL) {
    printf("Could not open log file. Exiting.\n");
    return -1;
  }
  
  FILE *fout = fopen(outputFile, "w");
  if(fout == NULL) {
    printf("Could not open output file. Exiting.\n");
    return -1;
  }
  
  char line[256];
  int lineNum = 1;
  while(fgets(line, sizeof(line), fp)) {
    if(strstr(line, pattern) != NULL) {
      fprintf(fout, "Line %d: %s", lineNum, line);
    }
    lineNum++;
  }
  
  fclose(fp);
  fclose(fout);
  
  return 0;
}