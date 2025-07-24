//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: shocked
#include <stdio.h>
#include <sys/statvfs.h>

int main(void) {
  struct statvfs fs;
  if (statvfs(".", &fs) != 0) {
    printf("Error retrieving file system stats.\n");
    return 1;
  }
  printf("Total disk space: %lu bytes\n", fs.f_blocks * fs.f_frsize);
  printf("Available disk space: %lu bytes\n", fs.f_bavail * fs.f_frsize);
  return 0;
}