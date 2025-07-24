//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/statvfs.h>

void analyzeDiskSpace(char* path) {
  struct statvfs stats;
  if (statvfs(path, &stats) != 0) {
    printf("Error: Unable to analyze disk space at path %s\n", path);
    exit(EXIT_FAILURE);
  }

  float totalSpace = (float)stats.f_blocks * stats.f_frsize / (1024 * 1024 * 1024);
  float freeSpace = (float)stats.f_bfree * stats.f_frsize / (1024 * 1024 * 1024);
  float usedSpace = totalSpace - freeSpace;

  printf("Disk Space Analysis for Path: %s\n", path);
  printf("Total Space: %.2f GB\n", totalSpace);
  printf("Used Space: %.2f GB\n", usedSpace);
  printf("Free Space: %.2f GB\n", freeSpace);
}

int main(int argc, char** argv) {
  if (argc < 2) {
    printf("Usage: %s <path>\n", argv[0]);
    return EXIT_FAILURE;
  }

  char* path = argv[1];
  analyzeDiskSpace(path);

  return EXIT_SUCCESS;
}