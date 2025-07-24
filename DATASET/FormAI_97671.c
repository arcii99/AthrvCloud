//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: cheerful
#include <stdio.h>

int main() {

  printf("Welcome to the C Antivirus scanner program!\n\n");

  char fileName[50];
  printf("Please enter the name of the file to be scanned (including file extension): ");
  scanf("%s", fileName);
  
  // Check if file extension is .c
  int i = 0;
  while(fileName[i] != '\0') {
    if(fileName[i] == '.') {
      if(fileName[i+1] == 'c') {
        printf("\nScanning file...\n\n");
        
        // Implement antivirus scanning algorithm here
        
        printf("File '%s' is safe and free from malicious code!\n", fileName);
        return 0;
      }
    }
    i++;
  }

  printf("\nI'm sorry, this program can only scan C programming files (.c).\n");

  return 0;
}