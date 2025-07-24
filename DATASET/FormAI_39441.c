//FormAI DATASET v1.0 Category: File Synchronizer ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void synchronize(char* from_file, char* to_file) {
  FILE* ffrom, * fto;
  ffrom = fopen(from_file, "r");
  if (ffrom == NULL) {
    printf("Oops! Could not open the source file. Check your file path and try again.\n");
    return;
  }
  fto = fopen(to_file, "w");
  if (fto == NULL) {
    printf("Oops! Could not open the destination file. Check your file path and try again.\n");
    return;
  }
  char c;
  while ((c = fgetc(ffrom)) != EOF) {
    fputc(c, fto);
  }
  printf("Hooray! Files synchronized successfully!\n");
  fclose(ffrom);
  fclose(fto);
}

int main() {
  char from_file[100], to_file[100];
  printf("Welcome to the C File Synchronizer! Let's get started...\n");
  printf("Enter the path and name of the file you want to synchronize: ");
  scanf("%s", from_file);
  printf("Enter the path and name of the target file: ");
  scanf("%s", to_file);
  synchronize(from_file, to_file);
  return 0;
}