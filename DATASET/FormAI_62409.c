//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: systematic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LEN 50

void scan(char* filename); // function to scan antivirus

int main() {

  char filename[MAX_LEN]; // buffer to store file name

  printf("\nEnter the file to be scanned with the C Antivirus: ");
  scanf("%s", filename);

  scan(filename); // scan file

  return 0;
}

void scan(char* filename) {

  FILE* file = fopen(filename, "r"); // open file

  if(file == NULL) {
    printf("\nError: %s file does not exist!", filename);
    return;
  }

  char contents[MAX_LEN]; // buffer to store contents of the file
  fread(contents, 1, MAX_LEN, file); // read contents of the file

  if(strstr(contents, "virus") != NULL) { // check contents for virus
    printf("\nWarning: %s file contains virus!", filename);
  }
  else {
    printf("\nThe %s file is safe.", filename);
  }

  fclose(file); // close file
}