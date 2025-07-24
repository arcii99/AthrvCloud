//FormAI DATASET v1.0 Category: File handling ; Style: excited
#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *fileptr; //Declare file pointer
  char c, filename[20]; //Declare character and filename variables

  printf("Enter the filename: "); //Ask user for filename input
  scanf("%s", filename);

  fileptr = fopen(filename, "r"); //Open file in read mode

  if (fileptr == NULL) { //Check if file exists or not
    printf("\nOops! The file does not exist.\n");
    exit(0); //Exit program
  }

  printf("\nContent of the file: \n\n");
  
  while ((c = fgetc(fileptr)) != EOF) { //Read file and print content to console
    printf("%c", c);
  }

  fclose(fileptr); //Close file

  return 0;
}