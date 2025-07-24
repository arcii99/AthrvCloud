//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: rigorous
#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
#include<string.h>

int main()
{
  DIR *directory;
  struct dirent *entry;
  char path[100];
  int total_size = 0;
  printf("Enter the path to find the disk space usage:");
  fgets(path, sizeof(path), stdin);
  path[strcspn(path, "\n")] = 0;
  directory = opendir(path);
  if(directory == NULL)
  {
    printf("Error: Couldn't open directory.\n");
    exit(1);
  }
  while((entry = readdir(directory)) != NULL) 
  {
    if(strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0)
    {
      char subpath[100];
      strcpy(subpath, path);
      strcat(subpath, "/");
      strcat(subpath, entry->d_name);
      DIR *subdirectory = opendir(subpath);
      if(subdirectory == NULL) 
      {
        FILE *file = fopen(subpath, "r");
        fseek(file, 0L, SEEK_END);
        int size = ftell(file) / 1024;
        printf("%-25s %5d KB\n", subpath, size);
        total_size += size;
        fclose(file);
      } 
      else 
      {
        closedir(subdirectory);
      }
    }
  }
  printf("\nTotal disk space usage: %d KB\n", total_size);
  closedir(directory);
  return 0;
}