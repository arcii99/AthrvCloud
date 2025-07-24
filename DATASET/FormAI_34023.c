//FormAI DATASET v1.0 Category: File handling ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

int main() {
  // create a file pointer and open file
  FILE *fp;
  fp = fopen("my_file.txt", "w");

  // write to file
  fprintf(fp, "Hello, this is my unique C file handling example program!\n");
  fprintf(fp, "It's so imaginative, you won't see another like it!\n");

  // close file
  fclose(fp);

  // open file for reading and print contents
  fp = fopen("my_file.txt", "r");
  if (fp == NULL) {
    printf("File not found\n");
    exit(1);
  }
  printf("Here's what's in the file:\n");
  char c = fgetc(fp);
  while (c != EOF) {
    printf("%c", c);
    c = fgetc(fp);
  }
  fclose(fp);

  // append to file
  fp = fopen("my_file.txt", "a");
  fprintf(fp, "Wow, this program is amazing! Keep up the good work.\n");
  fclose(fp);

  // open file for reading and print new contents
  fp = fopen("my_file.txt", "r");
  if (fp == NULL) {
    printf("File not found\n");
    exit(1);
  }
  printf("\nHere's what's in the file now:\n");
  c = fgetc(fp);
  while (c != EOF) {
    printf("%c", c);
    c = fgetc(fp);
  }
  fclose(fp);

  return 0;
}