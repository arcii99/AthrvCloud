//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: cheerful
#include <stdio.h>
#include <string.h>

int main() {
  char filename[100];
  int virus = 0;
  
  printf("Welcome to the Happy Antivirus Scanner!\n");
  printf("Please enter the name of the file you would like to scan: ");
  scanf("%s", filename);
  
  printf("Scanning file %s for viruses...\n", filename);
  FILE* fp = fopen(filename, "r");
  
  // Check if file exists
  if (fp == NULL) {
    printf("File not found! Please check the file name and try again.\n");
    return 1;
  }
  
  char line[1024];
  
  // Scan each line of the file for virus signatures
  while (fgets(line, sizeof(line), fp)) {
    if (strstr(line, "virus") != NULL || strstr(line, "malware") != NULL) {
      virus = 1;
      break;
    }
  }
  
  // Close the file
  fclose(fp);
  
  if (virus) {
    printf("Virus detected in file %s! Please delete the file immediately!\n", filename);
  } else {
    printf("No virus detected in file %s. Happy computing!\n", filename);
  }
  
  return 0;
}