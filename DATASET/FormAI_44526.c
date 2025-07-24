//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME 100

int scan_file(char *file_name);

int main(void) {
  char file_name[MAX_FILE_NAME];

  printf("Enter the name of the file to scan: ");
  scanf("%s", file_name);

  if (scan_file(file_name)) {
    printf("The file is infected.\n");
  } else {
    printf("The file is clean.\n");
  }

  return 0;
}

int scan_file(char *file_name) {
  FILE *file = fopen(file_name, "r");

  if (file == NULL) {
    printf("Error opening file.\n");
    return -1;
  }

  char virus[] = "malware";
  char buffer[100];
  int is_infected = 0;

  while (fgets(buffer, sizeof(buffer), file) != NULL) {
    if (strstr(buffer, virus) != NULL) {
      is_infected = 1;
      break;
    }
  }

  fclose(file);
  return is_infected;
}