//FormAI DATASET v1.0 Category: Ebook reader ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  char ebook_file[100];
  printf("Enter the name of the ebook file: ");
  scanf("%s", ebook_file);

  // Open the ebook file
  FILE *fp = fopen(ebook_file, "r");
  if (!fp) {
    printf("Could not open the ebook file!");
    return 1;
  }

  // Read the contents of the ebook file into memory
  fseek(fp, 0, SEEK_END);
  long file_size = ftell(fp);
  fseek(fp, 0, SEEK_SET);
  char *ebook_contents = malloc(file_size);
  fread(ebook_contents, 1, file_size, fp);
  fclose(fp);

  // Display the ebook contents
  printf("%s\n", ebook_contents);
  free(ebook_contents);

  return 0;
}