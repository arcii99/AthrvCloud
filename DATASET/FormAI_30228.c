//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char filepath[100];
  printf("Enter file path: ");
  scanf("%s", filepath);

  FILE *fp = fopen(filepath, "r");
  if(fp == NULL) {
    printf("Error opening file.\n");
    exit(1);
  }

  char virus_signature[] = "malware";
  char file_data[100];
  int is_infected = 0;

  while(fgets(file_data, 100, fp) != NULL) {
    if(strstr(file_data, virus_signature) != NULL) {
      printf("File is infected!\n");
      is_infected = 1;
      break;
    }
  }

  if(!is_infected) {
    printf("File is clean!\n");
  }

  fclose(fp);

  return 0;
}