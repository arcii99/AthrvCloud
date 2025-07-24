//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char file_name[100];
  printf("Enter the file name to scan: \n");
  scanf("%s", file_name);
  FILE *file = fopen(file_name, "r");
  if (file) {
    fseek(file, 0, SEEK_END);
    long fsize = ftell(file);
    fseek(file, 0, SEEK_SET); 

    char *contents = malloc(fsize + 1);
    fread(contents, 1, fsize, file);
    fclose(file);

    contents[fsize] = 0;
    char *virus = "malware";
    if (strstr(contents, virus) != NULL) {
      printf("File \"%s\" is infected with virus \"%s\".\n", file_name, virus);
      remove(file_name);
      printf("File \"%s\" has been removed.", file_name);
    } else {
      printf("File \"%s\" is not infected with any viruses.\n", file_name);
    }
    free(contents);
  } else {
      printf("File \"%s\" cannot be found.\n", file_name);
  }
  return 0;
}