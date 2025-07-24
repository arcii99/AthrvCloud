//FormAI DATASET v1.0 Category: File handling ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

int main() {

  // create and open a file
  FILE *fp;
  fp = fopen("example.txt", "w+");

  // check if file opened successfully
  if(fp == NULL) {
    printf("Error opening file!");
    exit(1);
  }

  // write data to the file
  char data[] = "This is my file handling example program!";
  fprintf(fp, "%s", data);

  // close the file
  fclose(fp);

  // reopen the file in read-only mode
  fp = fopen("example.txt", "r");

  // read the data from the file and print it to the console
  char c = fgetc(fp);
  while(c != EOF) {
    printf("%c", c);
    c = fgetc(fp);
  }

  // close the file again
  fclose(fp);

  // delete the file
  if(remove("example.txt") != 0) {
    printf("Error deleting file!");
  } else {
    printf("\nFile successfully deleted!");
  }

  return 0;
}