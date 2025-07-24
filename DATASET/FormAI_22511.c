//FormAI DATASET v1.0 Category: Data recovery tool ; Style: cheerful
#include <stdio.h>

int main() {
  printf("Welcome to the data recovery tool!\n");
  printf("Did you lose some important data? Don't worry, we can help!\n");
  printf("Just follow the steps below to recover your files.\n");

  // Step 1: Check if the file exists
  FILE *file = fopen("lost_data.txt", "r");
  if (file == NULL) {
    printf("Oops, we couldn't find your file. Please check the file name and try again.\n");
    return 1;
  }
  printf("File found successfully! Now let's recover the data.\n");

  // Step 2: Read the data from the file
  char data[100];
  fgets(data, 100, file);
  printf("Data successfully read from file: %s\n", data);

  // Step 3: Write the data to a new file
  FILE *new_file = fopen("recovered_data.txt", "w");
  fputs(data, new_file);
  fclose(new_file);
  printf("Data successfully recovered! Check the 'recovered_data.txt' file for your recovered data.\n");

  return 0;
}