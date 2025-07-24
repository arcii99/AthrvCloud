//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/statvfs.h>

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Usage: %s mountpoint\n", argv[0]);
    return -1;
  }

  struct statvfs stat;
  if (statvfs(argv[1], &stat) == -1) {
    printf("Error: unable to get information about %s\n", argv[1]);
    return -1;
  }

  long long free_bytes = stat.f_bfree * stat.f_frsize;
  long long total_bytes = stat.f_blocks * stat.f_frsize;

  printf("Total: %lld bytes, Free: %lld bytes, Usage: %.2lf%%\n",
         total_bytes, free_bytes,
         100.0 * (total_bytes - free_bytes) / total_bytes);

  return 0;
}