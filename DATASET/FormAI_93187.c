//FormAI DATASET v1.0 Category: File Synchronizer ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100

int main(int argc, char *argv[]) {
  if(argc != 3) {
    printf("Usage: %s <file1> <file2>\n", argv[0]);
    return 1;
  }

  FILE *fp1 = fopen(argv[1], "r");
  FILE *fp2 = fopen(argv[2], "w");
  
  if(fp1 == NULL || fp2 == NULL) {
    printf("Could not open files.\n");
    return 1;
  }

  char line1[MAX_LINE_LENGTH], line2[MAX_LINE_LENGTH];
  while(fgets(line1, MAX_LINE_LENGTH, fp1) != NULL) {
    fgets(line2, MAX_LINE_LENGTH, fp2);
    if(strcmp(line1, line2) != 0) {
      printf("Files out of sync. Fixing...\n");
      fseek(fp2, 0, SEEK_SET);
      fputs(line1, fp2);
    }
  }

  fclose(fp1);
  fclose(fp2);
  printf("Files synchronized successfully.\n");

  return 0;
}