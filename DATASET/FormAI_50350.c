//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1024

int main(int argc, char *argv[]) {
  char filename[100];
  FILE *fp;
  char *file_data = (char *) malloc(MAX_FILE_SIZE);

  printf("Enter filename: ");
  fgets(filename, 100, stdin);
  filename[strlen(filename)-1] = '\0';

  fp = fopen(filename, "r");
  if(fp == NULL) {
    printf("Error: Could not open file\n");
    return 1;
  }

  // Read file data into buffer
  fread(file_data, sizeof(char), MAX_FILE_SIZE, fp);

  // Check for virus signatures
  if(strstr(file_data, "malware") || strstr(file_data, "virus")) {
    printf("Warning: Virus detected!\n");
  } else {
    printf("File is clean\n");
  }

  // Free memory and close file
  free(file_data);
  fclose(fp);

  return 0;
}