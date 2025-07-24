//FormAI DATASET v1.0 Category: File Backup System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define BACKUP_DIR "/var/backups"
#define MAX_FILENAME_LENGTH 50

int main() {
  char source_dir[MAX_FILENAME_LENGTH];
  char backup_filename[MAX_FILENAME_LENGTH];
  char command[MAX_FILENAME_LENGTH * 2];
  time_t current_time;
  struct tm* time_info;
  char time_string[MAX_FILENAME_LENGTH];

  // Get user input for source directory
  printf("Enter directory to backup: ");
  fgets(source_dir, MAX_FILENAME_LENGTH, stdin);
  source_dir[strcspn(source_dir, "\n")] = 0;

  // Validate source directory exists
  if (access(source_dir, F_OK) == -1) {
    printf("Sorry, directory does not exist.\n");
    return 1;
  }

  // Get current time
  time(&current_time);
  time_info = localtime(&current_time);
  strftime(time_string, MAX_FILENAME_LENGTH, "%Y-%m-%d_%H:%M:%S", time_info);

  // Generate backup filename
  sprintf(backup_filename, "%s_%s.tar.gz", source_dir, time_string);

  // Create backup command
  sprintf(command, "tar -czvf %s %s", backup_filename, source_dir);

  // Run backup command
  system(command);

  // Validate backup file exists
  if (access(backup_filename, F_OK) == -1) {
    printf("Sorry, backup file not created.\n");
    return 1;
  }

  // Move backup file to backup directory
  sprintf(command, "mv %s %s", backup_filename, BACKUP_DIR);
  system(command);

  // Validate backup file was moved
  sprintf(backup_filename, "%s/%s", BACKUP_DIR, backup_filename);
  if (access(backup_filename, F_OK) == -1) {
    printf("Sorry, backup file not moved to backup directory.\n");
    return 1;
  }

  // Remove original source directory
  sprintf(command, "rm -rf %s", source_dir);
  system(command);

  // Validate source directory was removed
  if (access(source_dir, F_OK) != -1) {
    printf("Sorry, unable to remove source directory.\n");
    return 1;
  }

  // Notify user of successful backup
  printf("Backup successful! Backup file located at %s\n", backup_filename);

  return 0;
}