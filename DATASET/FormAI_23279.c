//FormAI DATASET v1.0 Category: Log analysis ; Style: peaceful
#include <stdio.h>
#include <string.h>

int main() {

  char log_data[1000]; // Buffer to store log messages
  int success_count = 0; // Number of successful transactions
  int error_count = 0; // Number of failed transactions

  FILE *fp = fopen("access.log", "r"); // Opening log file in read mode
  
  if (fp == NULL) { // Check if file exists or not
    printf("Error: Unable to open file\n");
    return 1;
  }

  while (fgets(log_data, 1000, fp) != NULL) { // Read log data line by line

    char *tok = strtok(log_data, " "); // Tokenize log data
    int count = 1; // Counter for number of tokens
    
    while (tok != NULL) {
      
      // Find IP address and check if it is a successful transaction or not
      if (count == 1) {
        if (strcmp(tok, "192.168.1.100") == 0) {
          success_count++;
        } else {
          error_count++;
        }
      }

      tok = strtok(NULL, " ");
      count++;
    }
  }

  fclose(fp); // Close the file
  
  // Output the results
  printf("Number of successful transactions: %d\n", success_count);
  printf("Number of failed transactions: %d\n", error_count);

  return 0;
}