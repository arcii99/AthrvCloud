//FormAI DATASET v1.0 Category: Log analysis ; Style: immersive
#include<stdio.h>
#include<stdlib.h>

int main() {
  FILE *filePointer;
  char logData[1000];

  filePointer = fopen("log_file.txt", "r");

  if(filePointer == NULL) {
    printf("File could not be opened.\n");
    exit(0);
  } else {
    printf("File opened successfully. Reading data...\n");

    while(fgets(logData, 1000, filePointer)) {
      printf("%s", logData);
      // do analysis here
    }

    fclose(filePointer);
    printf("\nData analysis complete.\n");
    exit(0);
  }
}