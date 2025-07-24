//FormAI DATASET v1.0 Category: File handling ; Style: grateful
#include <stdio.h>

int main() {
  FILE *fp;
  char data[] = "Hello, World!";

  // Creating a new file
  fp = fopen("myfile.txt", "w");

  // Writing data to the file
  if(fp != NULL) {
    fprintf(fp, "%s\n", data);
    printf("Data written to file successfully!\n");
    fclose(fp);
  }
  else {
    printf("Error opening file\n");
  }

  // Reading data from the file
  fp = fopen("myfile.txt", "r");
  char buffer[100];
  if(fp != NULL) {
    while(fgets(buffer, 100, fp)) {
      printf("%s", buffer);
    }
    fclose(fp);
  }
  else {
    printf("Error opening file\n");
  }

  return 0;
}