//FormAI DATASET v1.0 Category: Log analysis ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
  printf("Welcome to Log Analysis Program!");
  printf("\n\nPlease enter the name of the log file you want to analyze (with extension): ");
  
  char fileName[50];
  scanf("%s", fileName);  
  
  FILE *log = fopen(fileName, "r");
  
  if(log == NULL){
    printf("Error: File could not be opened!");
    exit(0);
  }
  
  printf("\nSuccessfully opened the file!\n");  
  printf("\nProcessing.....\n");
  
  int count = 0;
  char line[100];
  
  while(fgets(line, sizeof(line), log)){
    if(strstr(line, "ERROR") != NULL || strstr(line, "error") != NULL){     
      
      printf("\n%s", line);
      count++;      
    }    
  }  
  
  printf("\n\nAnalysis complete!");
  printf("\nTotal number of errors found in the log file: %d", count);
  
  fclose(log);
  
  return 0;
}