//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: funny
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
  printf("Welcome to the Metadata Extractor Pro(c)!\n");
  printf("Please input your file name:\n");
  
  char input[100];
  scanf("%s", input);
  
  printf("Scanning %s for juicy metadata...\n", input);
  sleep(1);
  
  printf("Extracting metadata...\n");
  sleep(1);
  
  printf("Sorting through irrelevant data...\n");
  sleep(1);
  
  printf("Aha! Found some metadata!\n");
  sleep(1);
  
  printf("Metadata:\n");
  printf("File Name: %s\n", input);
  printf("Creation Date: 01/01/1970\n");
  printf("Last Modified: 12/31/2020\n");
  printf("File Size: 42KB\n");
  printf("Author: John Doe\n");
  
  printf("Would you like to extract metadata from another file? (y/n)\n");
  char response;
  scanf("%c", &response);
  
  if(response == 'y' || response == 'Y'){
      printf("Sorry, this is a one-time-use program. Please re-run if you'd like to extract more metadata.\n");
  }else{
      printf("Thank you for using the Metadata Extractor Pro(c)!\n");
  }
  return 0;
}