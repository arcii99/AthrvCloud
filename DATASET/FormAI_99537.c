//FormAI DATASET v1.0 Category: File handling ; Style: enthusiastic
#include <stdio.h>

int main() {
  printf("Welcome to my File Handling program!\n");
  
  // create a file and write data to it
  FILE *file = fopen("example.txt", "w");
  if (file == NULL) {
    printf("Error creating file!\n");
    return 1;
  }
  fputs("Hello, World!", file);
  fclose(file);
  printf("Data has been written to file successfully!\n");
  
  // read data from file
  file = fopen("example.txt", "r");
  if (file == NULL) {
    printf("Error opening file!\n");
    return 1;
  }
  printf("Data in file: ");
  char ch = fgetc(file);
  while (ch != EOF) {
    printf("%c", ch);
    ch = fgetc(file);
  }
  fclose(file);
  
  // append data to file
  file = fopen("example.txt", "a");
  if (file == NULL) {
    printf("Error opening file!\n");
    return 1;
  }
  fputs("\nThis is some appended data!", file);
  fclose(file);
  printf("Data has been appended to file successfully!\n");
  
  return 0;
}