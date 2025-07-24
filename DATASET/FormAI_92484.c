//FormAI DATASET v1.0 Category: System boot optimizer ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 2048

int main(void){
  int i, j;
  char buffer[MAX_LINE_LENGTH];
  char command[MAX_LINE_LENGTH];
  char *tokens[MAX_LINE_LENGTH];
  int numTokens = 0;
  FILE *fp;

  // Open the hosts file as read-only
  fp = fopen("hosts", "r");
  if (fp == NULL){
    printf("ERROR: Unable to open hosts file.\n");
    return 1;
  }

  // Iterate over each line in the file
  while (fgets(buffer, MAX_LINE_LENGTH, fp) != NULL){
    numTokens = 0;
    tokens[numTokens] = strtok(buffer, " ");
    while (tokens[numTokens] != NULL){
      numTokens++;
      tokens[numTokens] = strtok(NULL, " ");
    }

    // If the line has at least 2 tokens, check if the first token is an IP address
    if (numTokens >= 2){
      for (i = 0; i < strlen(tokens[0]); i++){
        if (!((tokens[0][i] >= '0' && tokens[0][i] <= '9') || tokens[0][i] == '.')){
          break;
        }
      }
      // If the first token is an IP address, add it to the command
      if (i == strlen(tokens[0])){
        strcpy(command, "ping -c 3 "); // Set the first part of the command
        strcat(command, tokens[0]); // Add the IP address
        strcat(command, " > /dev/null"); // Redirect output to null
        system(command); // Run the command
      }
    }
  }

  // Clean up and exit
  fclose(fp);
  return 0;
}