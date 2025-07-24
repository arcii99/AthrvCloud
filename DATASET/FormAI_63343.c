//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char* argv[]) {
  if (argc != 2) {
    printf("Usage: %s [filepath]\n", argv[0]);
    return 1;
  }
  char* filepath = argv[1];
  struct stat buffer;
  int status = stat(filepath, &buffer);
  if (status != 0) {
    printf("Error: Unable to retrieve metadata for file %s.\n", filepath);
    return 1;
  }
  printf("Metadata for file %s:\n", filepath);
  printf("Size: %ld bytes\n", buffer.st_size);
  printf("Owner UID: %d\n", buffer.st_uid);
  printf("Group GID: %d\n", buffer.st_gid);
  printf("Last Access Time: %s", ctime(&buffer.st_atime));
  printf("Last Modification Time: %s", ctime(&buffer.st_mtime));
  printf("Last Inode Change Time: %s", ctime(&buffer.st_ctime));
  return 0;
}