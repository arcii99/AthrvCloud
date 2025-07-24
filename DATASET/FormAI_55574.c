//FormAI DATASET v1.0 Category: File handling ; Style: cheerful
#include <stdio.h>

int main() {
  printf("Welcome to Happy File Handling Program!\n");

  // Opening a new file for writing
  FILE *file = fopen("happy.txt", "w");

  // Checking if file opened successfully
  if(file == NULL) {
    printf("Oops, something went wrong. Unable to open file.\n");
    return 1;
  }

  // Writing happy messages to file
  fprintf(file, "Happiness is writing to a file.\n");
  fprintf(file, "Happiness is being able to read from a file.\n");

  // Closing file after writing
  fclose(file);

  // Opening the same file for reading
  file = fopen("happy.txt", "r");

  // Checking if file opened successfully
  if(file == NULL) {
    printf("Oops, something went wrong. Unable to read file.\n");
    return 1;
  }

  // Reading happy messages from file
  char happy_message[50];
  fgets(happy_message, 50, file);
  printf("%s", happy_message); // Printing first message

  fgets(happy_message, 50, file);
  printf("%s", happy_message); // Printing second message

  // Closing file after reading
  fclose(file);

  printf("\nAll happy messages read successfully!");

  return 0;
}