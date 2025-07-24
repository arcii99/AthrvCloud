//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: rigorous
#include <stdio.h>
#include <string.h>

int main() {
  char virus[] = "malware123"; // virus signature
  char filename[100];  // filename for scanning
  printf("Enter the filename to scan: ");
  scanf("%s", filename);
  FILE *file = fopen(filename, "r"); // open file
  if (file == NULL) {
    printf("File not found!\n");
    return 0;
  }
  char buffer[1024];  // buffer to hold file content while scanning
  int found = 0;  // flag to indicate virus found or not
  // read the file content chunk by chunk and check for virus signature
  while (fgets(buffer, sizeof(buffer), file)) {
    if (strstr(buffer, virus)) {
      found = 1;
      break;
    }
  }
  fclose(file);  // close file after scanning
  // print the result
  if (found) {
    printf("Virus found in file %s\n", filename);
  } else {
    printf("No virus found in file %s\n", filename);
  }
  return 0;
}