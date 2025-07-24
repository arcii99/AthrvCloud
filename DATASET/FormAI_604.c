//FormAI DATASET v1.0 Category: File Backup System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct File {
  char name[50];
  char type[5];
  long size;
  time_t date_modified;
};

void backupFiles(char *dir, struct File *files, int numFiles);
void printFiles(struct File *files, int numFiles);

int main() {
  char *directory = "/home/user/files/";
  struct File files[] = {
    {"file1", "txt", 2048, time(NULL)},
    {"file2", "pdf", 4096, time(NULL)},
    {"file3", "png", 8192, time(NULL)}
  };
  int numFiles = sizeof(files) / sizeof(files[0]);

  printf("Original Files:\n");
  printFiles(files, numFiles);

  backupFiles(directory, files, numFiles);

  return 0;
}

void backupFiles(char *dir, struct File *files, int numFiles) {
  char backupDir[100];
  strcpy(backupDir, dir);
  strcat(backupDir, "backup/");

  printf("Backing up files to %s...\n", backupDir);

  if (mkdir(backupDir, 0777) != 0) {
    printf("Unable to create backup directory!\n");
    return;
  }

  for (int i = 0; i < numFiles; i++) {
    char sourceFile[100];
    char backupFile[100];
    strcpy(sourceFile, dir);
    strcat(sourceFile, files[i].name);
    strcpy(backupFile, backupDir);
    strcat(backupFile, files[i].name);
    strcat(backupFile, ".bak");

    FILE *source = fopen(sourceFile, "rb");
    if (!source) {
      printf("Unable to open file: %s\n", sourceFile);
      continue;
    }

    FILE *backup = fopen(backupFile, "wb");
    if (!backup) {
      printf("Unable to create backup file: %s\n", backupFile);
      fclose(source);
      continue;
    }

    char buffer[1024];
    int bytesRead;
    while ((bytesRead = fread(buffer, 1, sizeof(buffer), source))) {
      fwrite(buffer, 1, bytesRead, backup);
    }

    fclose(source);
    fclose(backup);

    printf("Backed up %s to %s\n", sourceFile, backupFile);
  }
}

void printFiles(struct File *files, int numFiles) {
  printf("%-18s %-5s %-10s %s\n", "Name", "Type", "Size", "Date Modified");
  for (int i = 0; i < numFiles; i++) {
    char dateModified[20];
    strftime(dateModified, sizeof(dateModified), "%Y-%m-%d", localtime(&files[i].date_modified));
    printf("%-18s %-5s %10ld %s\n", files[i].name, files[i].type, files[i].size, dateModified);
  }
}