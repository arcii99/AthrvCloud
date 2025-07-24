//FormAI DATASET v1.0 Category: File handling ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

int main() {
  printf("Surprise! Let's create a file and see how it works.\n");

  // defining a file pointer
  FILE *fp;

  // creating and opening a file in write mode
  fp = fopen("surprise.txt", "w");

  // checking if the file is opened successfully
  if (fp == NULL) {
    printf("File could not be opened.\n");
    exit(1);
  }

  // writing data to the file
  fprintf(fp, "This is a surprise message from the code! ");

  // closing the file
  fclose(fp);

  // opening the file in read mode and displaying the message
  fp = fopen("surprise.txt", "r");

  // checking if the file is opened successfully
  if (fp == NULL) {
    printf("File could not be opened.\n");
    exit(1);
  }

  // displaying the message from the file
  printf("Message from the code: ");
  char c = getc(fp);
  while (c != EOF) {
    printf("%c", c);
    c = getc(fp);
  }

  // closing the file
  fclose(fp);

  printf("\nHave you found the surprise message in the file? Let's create another file.\n");

  // creating and opening a file in write mode
  fp = fopen("anotherSurprise.txt", "w");

  // checking if the file is opened successfully
  if (fp == NULL) {
    printf("File could not be opened.\n");
    exit(1);
  }

  // writing data to the file
  fprintf(fp, "You didn't expect another surprise, did you?");

  // closing the file
  fclose(fp);

  printf("The surprise file creation is completed.\n");

  return 0;
}