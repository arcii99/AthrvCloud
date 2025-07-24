//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <sys/statvfs.h>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <directory>\n", argv[0]);
    return 0;
  }
  
  struct statvfs fs_info;
  if (statvfs(argv[1], &fs_info) < 0) {
    printf("Could not get filesystem info for %s\n", argv[1]);
    return 0;
  }
  
  long long block_size = fs_info.f_frsize;
  long long total_blocks = fs_info.f_blocks;
  long long free_blocks = fs_info.f_bfree;
  long long used_blocks = total_blocks - free_blocks;
  
  printf("Disk space usage for %s:\n", argv[1]);
  printf("Total space: %.2f GB\n", (double)(total_blocks * block_size) / (1024 * 1024 * 1024));
  printf("Free space: %.2f GB\n", (double)(free_blocks * block_size) / (1024 * 1024 * 1024));
  printf("Used space: %.2f GB\n", (double)(used_blocks * block_size) / (1024 * 1024 * 1024));
  printf("Usage percentage: %.2f%%\n", (double)used_blocks / total_blocks * 100);
  
  return 0;
}