//FormAI DATASET v1.0 Category: File handling ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

  printf("Welcome to the curious file handling program!\n");

  // Let's create a file and write to it
  FILE *myFile;
  myFile = fopen("curious.txt", "w");

  // Check if file successfully opened
  if (myFile == NULL) {
    printf("Error opening file!\n");
    exit(1);
  }

  fprintf(myFile, "Hello curious world! This is my first file handling program.\n");

  fclose(myFile);

  // Let's read from the file and display the contents
  char text[100];
  myFile = fopen("curious.txt", "r");

  if (myFile == NULL) {
    printf("Error opening file!\n");
    exit(1);
  }

  while(fgets(text, 100, myFile)) {
    printf("%s", text);
  }

  fclose(myFile);

  // Now let's append to the file
  myFile = fopen("curious.txt", "a");

  if (myFile == NULL) {
    printf("Error opening file!\n");
    exit(1);
  }

  fprintf(myFile, "I'm appending to this file now. Isn't that curious?\n");

  fclose(myFile);

  // Let's read from the file again and display the updated contents
  myFile = fopen("curious.txt", "r");

  if (myFile == NULL) {
    printf("Error opening file!\n");
    exit(1);
  }

  while(fgets(text, 100, myFile)) {
    printf("%s", text);
  }

  fclose(myFile);

  // Let's rename the file
  rename("curious.txt", "mysterious.txt");
  printf("The file has been renamed to mysterious.txt.\n");

  // Let's delete the file
  remove("mysterious.txt");
  printf("The file has been deleted. Curious, isn't it?\n");

  return 0;
}