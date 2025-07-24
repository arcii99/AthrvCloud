//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

// function to recursively search for files and directories
void analyze_directory(const char* path, unsigned long long* total_size, unsigned long long* largest_size, char** largest_file) {
  DIR* directory = opendir(path);
  if (directory == NULL) {
    perror("Error opening directory");
    return;
  }

  // loop through directory entries
  struct dirent* entry;
  while ((entry = readdir(directory)) != NULL) {
    // skip current and parent directories
    if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
      continue;
    }

    char full_path[512];
    snprintf(full_path, sizeof(full_path), "%s/%s", path, entry->d_name);

    struct stat st;
    if (stat(full_path, &st) != 0) {
      perror("Error getting file information");
      continue;
    }

    if (S_ISDIR(st.st_mode)) {
      // it's a directory, analyze recursively
      analyze_directory(full_path, total_size, largest_size, largest_file);
    } else if (S_ISREG(st.st_mode)) {
      // it's a regular file, update total size and check if it's the largest file
      *total_size += st.st_size;
      if (st.st_size > *largest_size) {
        *largest_size = st.st_size;
        *largest_file = strdup(full_path);
      }
    }
  }

  closedir(directory);
}

int main(int argc, char** argv) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s directory\n", argv[0]);
    return 1;
  }

  unsigned long long total_size = 0;
  unsigned long long largest_size = 0;
  char* largest_file = NULL;

  analyze_directory(argv[1], &total_size, &largest_size, &largest_file);

  printf("Total size: %llu bytes (%llu MB)\n", total_size, total_size / 1024 / 1024);
  if (largest_file != NULL) {
    printf("Largest file: %s (%llu bytes)\n", largest_file, largest_size);
    free(largest_file);
  }

  return 0;
}