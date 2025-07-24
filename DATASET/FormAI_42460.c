//FormAI DATASET v1.0 Category: File Synchronizer ; Style: complete
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

void synchronize(char *dir1, char *dir2) {
  DIR *dp1, *dp2;
  struct dirent *entry1, *entry2;
  struct stat statbuf1, statbuf2;
  char path1[100], path2[100];

  // Open directories
  dp1 = opendir(dir1);
  dp2 = opendir(dir2);
  if (dp1 == NULL || dp2 == NULL) {
    printf("Error opening directories\n");
    exit(1);
  }

  // Read contents of dir1
  while ((entry1 = readdir(dp1)) != NULL) {
    sprintf(path1, "%s/%s", dir1, entry1->d_name);
    lstat(path1, &statbuf1);

    if (S_ISDIR(statbuf1.st_mode)) {
      // Ignore "." and ".." directories
      if (strcmp(entry1->d_name, ".") == 0 || strcmp(entry1->d_name, "..") == 0) {
        continue;
      }

      // Check if directory exists in dir2
      sprintf(path2, "%s/%s", dir2, entry1->d_name);
      if (opendir(path2) == NULL) {
        // If directory doesn't exist, create it
        mkdir(path2, statbuf1.st_mode);
      }

      // Recursively call synchronize on subdirectories
      synchronize(path1, path2);
    } else {
      // Check if file exists in dir2
      sprintf(path2, "%s/%s", dir2, entry1->d_name);
      if (access(path2, F_OK) == -1) {
        // If file doesn't exist, copy it
        FILE *fromFile, *toFile;
        fromFile = fopen(path1, "rb");
        toFile = fopen(path2, "wb");
        char buffer[1024];
        int count = 0;
        while ((count = fread(buffer, 1, sizeof(buffer), fromFile)) > 0) {
          fwrite(buffer, 1, count, toFile);
        }
        fclose(fromFile);
        fclose(toFile);
      } else {
        // If file exists, compare modification times
        lstat(path2, &statbuf2);
        if (statbuf1.st_mtime > statbuf2.st_mtime) {
          // If file in dir1 is newer, copy it
          FILE *fromFile, *toFile;
          fromFile = fopen(path1, "rb");
          toFile = fopen(path2, "wb");
          char buffer[1024];
          int count = 0;
          while ((count = fread(buffer, 1, sizeof(buffer), fromFile)) > 0) {
            fwrite(buffer, 1, count, toFile);
          }
          fclose(fromFile);
          fclose(toFile);
        } else if (statbuf1.st_mtime < statbuf2.st_mtime) {
          // If file in dir2 is newer, copy it
          FILE *fromFile, *toFile;
          fromFile = fopen(path2, "rb");
          toFile = fopen(path1, "wb");
          char buffer[1024];
          int count = 0;
          while ((count = fread(buffer, 1, sizeof(buffer), fromFile)) > 0) {
            fwrite(buffer, 1, count, toFile);
          }
          fclose(fromFile);
          fclose(toFile);
        }
      }
    }
  }

  // Read contents of dir2
  while ((entry2 = readdir(dp2)) != NULL) {
    sprintf(path2, "%s/%s", dir2, entry2->d_name);
    lstat(path2, &statbuf2);

    if (S_ISDIR(statbuf2.st_mode)) {
      // Ignore "." and ".." directories
      if (strcmp(entry2->d_name, ".") == 0 || strcmp(entry2->d_name, "..") == 0) {
        continue;
      }

      // Check if directory exists in dir1
      sprintf(path1, "%s/%s", dir1, entry2->d_name);
      if (opendir(path1) == NULL) {
        // If directory doesn't exist, create it
        mkdir(path1, statbuf2.st_mode);
      }

      // Recursively call synchronize on subdirectories
      synchronize(path1, path2);
    } else {
      // Check if file exists in dir1 (this has already been done above)
      // If file doesn't exist, it will be copied later
    }
  }

  closedir(dp1);
  closedir(dp2);
}

int main(int argc, char **argv) {
  if (argc != 3) {
    printf("Usage: %s [dir1] [dir2]\n", argv[0]);
    exit(1);
  }

  synchronize(argv[1], argv[2]);

  return 0;
}