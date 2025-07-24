//FormAI DATASET v1.0 Category: File Backup System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define FILE_BACKUP_COUNT 10

struct FileInfo {
  char name[256];
  size_t size;
  time_t last_modified;
};

struct FileBackup {
  struct FileInfo info;
  char* data;
};

struct FileBackupSystem {
  struct FileBackup backups[FILE_BACKUP_COUNT];
  int count;
};

void addBackup(struct FileBackupSystem* system, struct FileBackup backup) {
  if (system->count >= FILE_BACKUP_COUNT) {
    printf("Cannot add more backups. Backup limit reached.\n");
    return;
  }

  system->backups[system->count] = backup;
  system->count++;
}

void removeBackup(struct FileBackupSystem* system, int index) {
  if (index < 0 || index >= system->count) {
    printf("Invalid index. Cannot remove backup.\n");
    return;
  }

  for (int i = index; i < system->count - 1; i++) {
    system->backups[i] = system->backups[i + 1];
  }

  system->count--;
}

void printFileInfo(struct FileInfo info) {
  printf("%s\n", info.name);
  printf("Size: %zu bytes\n", info.size);
  printf("Last modified: %s", ctime(&info.last_modified));
}

void printFileBackup(struct FileBackup backup) {
  printFileInfo(backup.info);
  printf("Data: %s\n", backup.data);
}

void printFileBackupSystem(struct FileBackupSystem system) {
  for (int i = 0; i < system.count; i++) {
    printf("Backup #%d:\n", i + 1);
    printFileBackup(system.backups[i]);
    printf("\n");
  }
}

struct FileBackup createBackup(char* filename) {
  struct FileBackup backup;
  strcpy(backup.info.name, filename);
  backup.info.last_modified = time(NULL);
  backup.data = NULL;

  FILE* file = fopen(filename, "rb");

  if (file == NULL) {
    printf("Failed to open file '%s' for backup.\n", filename);
    return backup;
  }

  fseek(file, 0, SEEK_END);
  backup.info.size = ftell(file);
  rewind(file);

  backup.data = (char*) malloc(backup.info.size * sizeof(char));
  fread(backup.data, sizeof(char), backup.info.size, file);

  fclose(file);

  printf("Successfully backed up file '%s'.\n", filename);
  return backup;
}

int main() {
  struct FileBackupSystem system;
  system.count = 0;

  char* filenames[] = {"file1.txt", "file2.txt", "file3.txt", "file4.txt", "file5.txt"};

  for (int i = 0; i < sizeof(filenames) / sizeof(filenames[0]); i++) {
    struct FileBackup backup = createBackup(filenames[i]);
    addBackup(&system, backup);
  }

  printFileBackupSystem(system);

  removeBackup(&system, 2);

  printf("\nAfter removing backup #3:\n\n");

  printFileBackupSystem(system);

  return 0;
}