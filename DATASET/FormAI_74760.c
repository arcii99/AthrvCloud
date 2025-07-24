//FormAI DATASET v1.0 Category: System administration ; Style: enthusiastic
#include <stdio.h>

int main() {
  printf("Welcome to the System Administration Program!\n");
  
  // user input for file name
  printf("Please enter the name of the file you would like to create: ");
  char fileName[50];
  scanf("%s", fileName);

  // create file
  FILE *fp;
  fp = fopen(fileName, "w+");
  if (fp == NULL) {
    printf("Error creating file. Please try again.\n");
    return 1;
  }
  fprintf(fp, "Congratulations! You just created a new file.\n");

  // display file contents
  printf("\nFile contents:\n");
  char c;
  fseek(fp, 0, SEEK_SET); // move file pointer to start of file
  while ((c = fgetc(fp)) != EOF) {
    printf("%c", c);
  }

  // close file
  fclose(fp);

  // user input for directory name
  printf("\nPlease enter the name of the directory you would like to create: ");
  char directoryName[50];
  scanf("%s", directoryName);

  // create directory
  int status = mkdir(directoryName);
  if (status != 0) {
    printf("Error creating directory. Please try again.\n");
    return 1;
  }
  printf("\nCongratulations! You just created a new directory.\n");

  return 0;
}