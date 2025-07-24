//FormAI DATASET v1.0 Category: File handling ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

int main() {
  printf("Wow! You want to see a unique C File handling program? Well, hold on to your hats, because here it comes!\n");

  // Create a new file to write to
  FILE *file_write = fopen("surprise.txt", "w");

  if (file_write == NULL) {
    printf("Oops! Something went wrong creating the file. Maybe try again?\n");
    return 1;
  }

  // Write a surprise message to the file
  fprintf(file_write, "Congratulations! You found the hidden message!\n");

  // Close the file
  fclose(file_write);

  printf("But wait, there's more! Let's read the file and see what the surprise message says...\n");

  // Open the file to read from
  FILE *file_read = fopen("surprise.txt", "r");

  if (file_read == NULL) {
    printf("Uh oh, the file seems to be missing. Better check your directory!");
    return 1;
  }

  // Read the message from the file and print it to the console
  char message[100];
  fscanf(file_read, "%[^\n]", message);
  printf("%s\n", message);

  // Close the file
  fclose(file_read);

  printf("Wasn't that a surprise? Your very own hidden message, all thanks to this fun little C program!\n");

  return 0;
}