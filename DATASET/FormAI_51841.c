//FormAI DATASET v1.0 Category: File handling ; Style: introspective
#include <stdio.h>

int main() {
  FILE *fp;
  char ch, file_name[25];

  printf("Enter the name of file you wish to see: ");
  fgets(file_name, 25, stdin);

  // Removing trailing newline character from file_name
  file_name[strcspn(file_name, "\n")] = 0;

  fp = fopen(file_name, "r"); // opening the file in read mode

  if(fp == NULL) {
    perror("Error while opening the file.\n"); // print an error message if unable to open the file
    return -1;
  }

  printf("The contents of %s file are:\n", file_name);

  while((ch = fgetc(fp)) != EOF) { // checking if the end of file is reached
    printf("%c", ch); // printing the character
  }

  fclose(fp); // closing the file
  return 0;
}