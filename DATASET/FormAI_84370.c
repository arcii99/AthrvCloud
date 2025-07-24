//FormAI DATASET v1.0 Category: File Synchronizer ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

void sync_files(char* src_dir, char* dest_dir) {
  DIR *d = opendir(src_dir);
  struct dirent *dir_entry;

  // Crawl through source directory and sync each file
  while ((dir_entry = readdir(d)) != NULL) {
    if (dir_entry->d_type == DT_REG) { // If it's a regular file
      char src[1024], dest[1024];
      strcpy(src, src_dir);
      strcat(src, "/");
      strcat(src, dir_entry->d_name);
      strcpy(dest, dest_dir);
      strcat(dest, "/");
      strcat(dest, dir_entry->d_name);

      sync_file(src, dest);
    }
  }
  closedir(d);
}

void sync_file(char* src, char* dest) {
  struct stat src_stat, dest_stat;

  if (stat(src, &src_stat) == -1) { // Couldn't get file status
    perror(src);
    return;
  }
  if (stat(dest, &dest_stat) == -1) { // Destination file doesn't exist
    copy_file(src, dest);
    return;
  }
  if (src_stat.st_mtime > dest_stat.st_mtime) { // Source file is newer
    copy_file(src, dest);
  }
}

void copy_file(char* src, char* dest) {
  FILE *src_file = fopen(src, "rb");
  FILE *dest_file = fopen(dest, "wb");
  char buffer[1024];
  size_t bytes_read;

  if (src_file == NULL) { // Source file couldn't be opened
    perror(src);
    return;
  }
  if (dest_file == NULL) { // Destination file couldn't be opened
    perror(dest);
    fclose(src_file);
    return;
    }

  while ((bytes_read = fread(buffer, 1, sizeof buffer, src_file)) > 0) {
    fwrite(buffer, 1, bytes_read, dest_file);
  }
  fclose(src_file);
  fclose(dest_file);
}

int main(int argc, char* argv[]) {
  if (argc != 3) { // Both directories must be specified
    fprintf(stderr, "Usage: %s source-dir destination-dir\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  sync_files(argv[1], argv[2]);

  return 0;
}