//FormAI DATASET v1.0 Category: File handling ; Style: excited
#include <stdio.h>
#include <string.h>

int main() {
  printf("Welcome to my exciting file handling program!\n");

  // Creating a file
  FILE *fptr;
  fptr = fopen("example.txt", "w");

  // Writing to the file
  char message[100] = "This is so much fun! I love file handling!\n";
  fputs(message, fptr);

  // Closing the file
  fclose(fptr);

  printf("I just created and wrote to a file! But I'm not done yet...\n\n");

  // Opening the file to read
  fptr = fopen("example.txt", "r");

  // Reading from the file
  char buffer[100];
  while(fgets(buffer, 100, fptr)) {
    printf("%s", buffer);
  }

  // Closing the file
  fclose(fptr);

  printf("\nI just read from the file too! I'm a file handling master!\n");

  // Appending to the file
  fptr = fopen("example.txt", "a");
  char more_message[100] = "I can't wait to write even more to this file!\n";
  fputs(more_message, fptr);
  fclose(fptr);

  printf("\nAnd now I just appended more text to the file! This is amazing!\n");

  return 0;
}