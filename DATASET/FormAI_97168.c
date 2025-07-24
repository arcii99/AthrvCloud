//FormAI DATASET v1.0 Category: File Backup System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILENAME_LENGTH 50
#define MAX_FILEPATH_LENGTH 100

int main() {
  char filepath[MAX_FILEPATH_LENGTH];
  char filename[MAX_FILENAME_LENGTH];
  char command[MAX_FILEPATH_LENGTH + MAX_FILENAME_LENGTH + 50];
  time_t t = time(NULL);
  struct tm tm = *localtime(&t);
  sprintf(filepath, "backup_%04d-%02d-%02d/", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);
  
  // create backup directory with today's date
  system("mkdir -p $HOME/backups/");
  sprintf(command, "mkdir -p $HOME/backups/%s", filepath);
  system(command);
  
  printf("Enter the file to backup (relative or full path):\n");
  scanf("%s", filename);
  
  // generate backup file name
  char backup_name[MAX_FILENAME_LENGTH + 30];
  sprintf(backup_name, "%s_%02d-%02d-%02d.backup", filename, tm.tm_hour, tm.tm_min, tm.tm_sec);
  
  // copy file to backup folder
  sprintf(command, "cp %s $HOME/backups/%s/%s", filename, filepath, backup_name);
  system(command);
  printf("Backup of %s created!\n", filename);
  
  return 0;
}