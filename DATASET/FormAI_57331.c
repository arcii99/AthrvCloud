//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: Ken Thompson
#include <stdio.h>

/**
 * Ken Thompson Style Antivirus Scanner
 * Searches for malicious code and terminates it if found
 */

int main() {
  char buffer[1024];
  FILE *fp;
  char *pattern = "malware";
  char *status = "clean";
  
  /** Open file to be scanned */
  fp = fopen("file.exe", "r");
  
  /** Check if file exists */
  if(fp == NULL) {
    printf("Error: Unable to open file\n");
    return 1;
  }
  
  /** Loop through file looking for malicious pattern */
  while(fgets(buffer, 1024, fp)) {
    if(strstr(buffer, pattern) != NULL) {
      /** Malicious pattern found, terminate program */
      status = "infected";
      system("rm file.exe");
      printf("Malware detected and removed!\n");
      break;
    }
  }
  
  /** Close file */
  fclose(fp);
  
  /** Print scanning results */
  printf("File is %s\n", status);
  
  return 0;
}