//FormAI DATASET v1.0 Category: File handling ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

int main() {
  // Welcome Message
  printf("Welcome to the File Handling program!\n\n");

  // Get user's preferred filename
  char filename[50];
  printf("Please enter your preferred filename: ");
  scanf("%s", filename);

  // Check if file exists
  FILE *fp;
  fp = fopen(filename, "r");
  if (fp != NULL) {
    printf("\nThe file %s already exists!\nDo you want to overwrite it? (Y/N): ", filename);
    char user_choice;
    scanf(" %c", &user_choice);
    if (user_choice == 'N') {
      printf("\nExiting program...\n");
      exit(0);
    }
  }

  // Prompt user to enter file data
  printf("\nPlease enter the contents of the file:\n");
  char file_data[500];
  scanf(" %[^\n]s", file_data);

  // Create file and write data to it
  fp = fopen(filename, "w");
  fprintf(fp, "%s\n", file_data);
  fclose(fp);

  // Read and print file data
  fp = fopen(filename, "r");
  printf("\nThe contents of the file %s are:\n", filename);
  char file_contents[500];
  while (fgets(file_contents, sizeof file_contents, fp) != NULL) {
    printf("%s", file_contents);
  }
  fclose(fp);

  // Thank you message
  printf("\nThank you for using the File Handling program!\n");

  return 0;
}