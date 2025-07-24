//FormAI DATASET v1.0 Category: File handling ; Style: excited
#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *fp;
  char filename[50], ch;

  printf("Welcome to my unique C File handling program!!\n\n");
  printf("Please enter the name of the file you want to create: ");
  scanf("%s", filename);

  fp = fopen(filename, "w"); // Opening the file in write mode

  if (fp == NULL) {
    printf("Oops! Something went wrong while creating the file. :(\n");
    exit(1);
  }

  printf("\nGreat! Now, you can start writing into the file. :)");

  while (1) {
    ch = getchar();
    if (ch == EOF) break;
    // Writing the character into the file
    putc(ch, fp);
  }

  printf("\nEverything is written successfully!\n");
  printf("Now, let's read the contents of the file.\n\n");

  char line[5000];
  fseek(fp, 0, SEEK_SET); // Moving the file pointer to the beginning of the file

  while (fgets(line, sizeof(line), fp)) {
    printf("%s", line);
  }

  printf("\nThanks for using my program. :D\n");
  fclose(fp); // Closing the file

  return 0;
}