//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: real-life
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

/*
1. Get the file name and check if it exits
2. Extract the metadata information such as author, date, title, description etc.
3. Display the extracted metadata
*/

int main(int argc, char *argv[]) {
  if(argc < 2) {
    printf("Error! Usage: ./metadata_extractor <filename>\n");
    return 1;
  } else {
    char *filename = argv[1];
    char author[50], date[25], title[50], description[100];
    char line[100];
    int i;
    FILE *fp = fopen(filename, "r");

    if(fp == NULL) {
      printf("Error! Unable to open file: %s\n", filename);
      return 1;
    }

    // Extract author metadata from file
    while(fgets(line, 100, fp) != NULL) {
      if(strstr(line, "Author:")) {
        sscanf(line, "%*s %*s %[^\n]", author);
        break;
      }
    }

    // Extract date metadata from file
    rewind(fp);
    while(fgets(line, 100, fp) != NULL) {
      if(strstr(line, "Date:")) {
        sscanf(line, "%*s %*s %[^\n]", date);
        break;
      }
    }

    // Extract title metadata from file
    rewind(fp);
    while(fgets(line, 100, fp) != NULL) {
      if(strstr(line, "Title:")) {
        sscanf(line, "%*s %[^\n]", title);
        break;
      }
    }

    // Extract description metadata from file
    rewind(fp);
    while(fgets(line, 100, fp) != NULL) {
      if(strstr(line, "Description:")) {
        sscanf(line, "%*s %[^\n]", description);
        break;
      }
    }

    // Display extracted metadata
    printf("Metadata Information of file '%s':\n", filename);
    printf("--------------------------------------\n");
    printf("Author: %s\n", author);
    printf("Date: %s\n", date);
    printf("Title: %s\n", title);
    printf("Description: %s\n", description);

    fclose(fp);
    return 0;
  }
}