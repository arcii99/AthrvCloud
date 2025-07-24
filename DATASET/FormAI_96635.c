//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <sys/statvfs.h>

int main() {
  struct statvfs buffer;
  unsigned long long free_space, total_space, used_space;

  if (statvfs(".", &buffer)) {
    printf("Error: Failed to get file system statistics\n");
    exit(EXIT_FAILURE);
  }

  free_space = (unsigned long long)buffer.f_bsize * buffer.f_bfree;
  total_space = (unsigned long long)buffer.f_bsize * buffer.f_blocks;
  used_space = total_space - free_space;

  printf("Total space in the file system: %llu bytes\n", total_space);
  printf("Used space in the file system: %llu bytes\n", used_space);
  printf("Free space in the file system: %llu bytes\n", free_space);

  double used_percent = ((double)used_space / total_space) * 100.0;
  double free_percent = ((double)free_space / total_space) * 100.0;

  printf("\nSpace Usage:\n");
  printf("Used: %.2f%%\n", used_percent);
  printf("Free: %.2f%%\n", free_percent);
  
  return 0;
}