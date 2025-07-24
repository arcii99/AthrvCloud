//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: Dennis Ritchie
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>

int main(){
  DIR *dir;
  struct dirent *ent;
  struct stat st;
  long long int totalSize = 0;

  if ((dir = opendir("."))!= NULL){
    printf("Disk space analysis:\n\n");
    printf("Filename\t\tSize\n\n");
    while((ent = readdir(dir)) != NULL){
      lstat(ent->d_name, &st);
      if(strcmp(ent->d_name,".")!= 0 && strcmp(ent->d_name,"..")!= 0){
        long long int fileSize = (long long int) st.st_size;
        printf("%-16s\t", ent->d_name);
        printf("%lld bytes\n", fileSize);
        totalSize += fileSize;
      }
    }
    closedir(dir);
    printf("\nTotal disk space used: %lld bytes\n", totalSize);
  }else{
    printf("Unable to open directory\n");
  }
  return 0;
}