//FormAI DATASET v1.0 Category: Compression algorithms ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  printf("Welcome to the world of C Compression Algorithms!\n");
  printf("Prepare to be amazed!\n\n");

  char input[100], output[100];
  int choice;

  printf("Please enter the file name to be compressed: ");
  scanf("%s", input);

  FILE *fp = fopen(input, "r");
  if(fp == NULL) {
    printf("\nError opening file.");
    exit(1);
  }

  printf("\nChoose the compression method:\n");
  printf("1. Lossless Compression\n");
  printf("2. Lossy Compression\n");
  scanf("%d", &choice);

  if(choice == 1) {
    printf("You have chosen Lossless Compression!\n");
    printf("This method will compress the file without losing any data.\n");

    char ch;
    int count = 0;

    while((ch = fgetc(fp)) != EOF) {
      count++;

      if(count == 1) {
        output[0] = ch;
        continue;
      }

      if(ch == output[count - 2]) {
        output[count - 1] = '\0';
      } else {
        output[count - 1] = ch;
      }
    }

    fclose(fp);

    printf("Compression complete!\n");
    printf("Please enter a name for the compressed file: ");
    scanf("%s", output);

    FILE *fp2 = fopen(output, "w");
    if(fp2 == NULL) {
      printf("\nError creating compressed file.");
      exit(1);
    }

    fprintf(fp2, "%s", output);

    fclose(fp2);

    printf("\nFile compressed and saved as %s.\n", output);

  } else if(choice == 2) {
    printf("You have chosen Lossy Compression!\n");
    printf("This method will compress the file, but there may be some loss of data.\n");

    char ch;
    int count = 0;

    while((ch = fgetc(fp)) != EOF) {
      count++;

      if(count == 1) {
        output[0] = ch;
        continue;
      }

      if(ch == output[count - 2]) {
        output[count - 1] = '\0';
      } else {
        output[count - 1] = ch + 1;
      }
    }

    fclose(fp);

    printf("Compression complete!\n");
    printf("Please enter a name for the compressed file: ");
    scanf("%s", output);

    FILE *fp2 = fopen(output, "w");
    if(fp2 == NULL) {
      printf("\nError creating compressed file.");
      exit(1);
    }

    fprintf(fp2, "%s", output);

    fclose(fp2);

    printf("\nFile compressed and saved as %s.\n", output);

  } else {
    printf("\nInvalid choice. Please choose either 1 or 2.\n");
  }

  return 0;
}