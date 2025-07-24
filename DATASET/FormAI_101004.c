//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: ephemeral
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
  char virusSignature[] = "AABBCCDDEEFF";
  char filePath[100];
  FILE *file;
  int i, j;

  if (argc < 2) {
    printf("Please provide the file path to scan.\n");
    return 1;
  }

  strcpy(filePath, argv[1]);

  file = fopen(filePath, "r");

  if (!file) {
    printf("Error opening file.\n");
    return 1;
  }

  fseek(file, 0, SEEK_END);
  int fileSize = ftell(file);
  fseek(file, 0, SEEK_SET);

  char fileContent[fileSize];
  fread(fileContent, 1, fileSize, file);
  fclose(file);

  for (i = 0; i < fileSize; i++) {
    if (fileContent[i] == virusSignature[0]) {
      for (j = 1; j < strlen(virusSignature); j++) {
        if (fileContent[i+j] != virusSignature[j]) {
          break;
        }
      }

      if (j == strlen(virusSignature)) {
        printf("Virus found in the file.\n");
        return 0;
      }
    }
  }

  printf("No virus found in the file.\n");
  return 0;
}