//FormAI DATASET v1.0 Category: File Backup System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILES 100
#define MAX_FILE_NAME_LENGTH 50
#define MAX_PATH_LENGTH 100

struct file {
  char filename[MAX_FILE_NAME_LENGTH];
  char path[MAX_PATH_LENGTH];
  time_t lastModified;
};

struct backup {
  struct file files[MAX_FILES];
  int numFiles;
  time_t timestamp;
};

void backupFile(struct file f, struct backup *b) {
  if (b->numFiles >= MAX_FILES) {
    printf("Backup is full\n");
    return;
  }
  b->files[b->numFiles++] = f;
  b->timestamp = time(NULL);
}

void displayBackup(struct backup b) {
  printf("Backup taken on %s", ctime(&b.timestamp));
  printf("Files included in backup:\n");
  for (int i = 0; i < b.numFiles; i++) {
    printf("\t%s (%s)\n", b.files[i].filename, b.files[i].path);
  }
}

int main() {
  struct backup b1 = {0};
  struct file f1 = {"file1.txt", "path/to/file1.txt", time(NULL)};
  backupFile(f1, &b1);

  struct file f2 = {"file2.txt", "path/to/file2.txt", time(NULL)};
  backupFile(f2, &b1);

  displayBackup(b1);

  return 0;
}