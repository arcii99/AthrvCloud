//FormAI DATASET v1.0 Category: File Backup System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void backupFile(char *filename) {
  char backup[100];
  
  // Creating backup file name
  sprintf(backup, "%s.bak", filename);

  // Opening original and backup files in binary mode
  FILE *originalFile = fopen(filename, "rb");
  FILE *backupFile = fopen(backup, "wb");

  if(!originalFile) {
    printf("Could not open original file %s.", filename);
    return;
  }

  if(!backupFile) {
    printf("Could not create backup file %s.", backup);
    return;
  }

  // Copying contents of original file to backup file
  int ch = getc(originalFile);
  while(ch != EOF) {
    putc(ch, backupFile);
    ch = getc(originalFile);
  }

  printf("Backup file created for %s.", filename);

  // Closing file pointers
  fclose(originalFile);
  fclose(backupFile);
}

int main() {
  char filename[100];

  printf("Enter file name: ");
  scanf("%s", filename);

  backupFile(filename);

  return 0;
}