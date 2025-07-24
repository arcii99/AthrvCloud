//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <sys/statvfs.h>

int main() {
  struct statvfs stats;
  int result = statvfs(".", &stats);

  if(result == -1) {
    printf("Error: Unable to retrieve file system statistics.\n");
    exit(EXIT_FAILURE);
  }

  double block_size = (double)(stats.f_frsize);
  double total_space = (double)(stats.f_blocks) * block_size;
  double free_space = (double)(stats.f_bfree) * block_size;
  double used_space = total_space - free_space;

  printf("Total space on disk: %.2f GB\n", total_space / 1073741824.0);
  printf("Free space on disk: %.2f GB\n", free_space / 1073741824.0);
  printf("Used space on disk: %.2f GB\n", used_space / 1073741824.0);

  return 0;
}