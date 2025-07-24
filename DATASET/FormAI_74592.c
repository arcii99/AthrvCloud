//FormAI DATASET v1.0 Category: File handling ; Style: creative
#include <stdio.h>

int main() {
  // Create file and write to it
  FILE* fp = fopen("myFile.txt", "w");
  fprintf(fp, "Hello World!\n");
  fclose(fp);

  // Read from file
  fp = fopen("myFile.txt", "r");
  char buffer[255];
  fscanf(fp, "%s", buffer);
  printf("File contents: %s\n", buffer);
  fclose(fp);

  // Append to file
  fp = fopen("myFile.txt", "a");
  fprintf(fp, "This is a new line.\n");
  fclose(fp);

  // Read from file again
  fp = fopen("myFile.txt", "r");
  while (fgets(buffer, 255, fp)) {
    printf("%s", buffer);
  }
  fclose(fp);

  return 0; 
}