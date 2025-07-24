//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char fileName[50];
  char virus[10] = "malware";
  printf("Welcome to the C Antivirus scanner. Please enter the file name: ");
  scanf("%s", fileName);
  FILE *filePtr = fopen(fileName, "r");
  if (filePtr == NULL) {
    printf("File not found. Please try again.\n");
    return 1;
  }
  printf("Scanning file for viruses...\n");
  char fileContent[1000];
  int i = 0;
  int virusCount = 0;
  while (!feof(filePtr)) {
    fgets(fileContent, 1000, filePtr);
    if (strstr(fileContent, virus) != NULL) {
      virusCount++;
      printf("Virus found on line %d: %s\n", i+1, fileContent);
    }
    i++;
  }
  printf("Scan complete. %d virus(es) found.", virusCount);
  fclose(filePtr);
  return 0;
}