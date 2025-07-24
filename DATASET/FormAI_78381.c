//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <dirent.h>
#include <string.h>

bool is_infected(char *filename){
  FILE *file = fopen(filename, "rb");
  if(file == NULL){
    return false;
  }
  char buffer[100];
  fread(buffer, sizeof(char), 100, file);
  fclose(file);
  if(strstr(buffer, "malware")){
    printf("%s is infected with malware.\n", filename);
    return true;
  }
  return false;
}

int main(void) {
  DIR *d;
  struct dirent *dir;
  d = opendir(".");
  if(d){
    while((dir = readdir(d)) != NULL){
      if(!strcmp(dir->d_name, ".") || !strcmp(dir->d_name, "..")){
        continue;
      }
      if(is_infected(dir->d_name)){
        //delete or move the infected file
      }
    }
    closedir(d);
  }
  return 0;
}