//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: visionary
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LEN 1024

int main(){
  FILE *fp;
  char *filename = "example.csv";
  char line[MAX_LEN];
  char *token;

  fp = fopen(filename, "r");

  if(fp == NULL){
    printf("Error opening file\n");
    exit(1);
  }

  while(fgets(line, MAX_LEN, fp)){
    token = strtok(line, ",");
    while(token != NULL){
      printf("%s", token);
      token = strtok(NULL, ",");
    }
    printf("\n");
  }

  fclose(fp);
  return 0;
}