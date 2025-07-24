//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// declaring the structure to store metadata information
struct MetaInfo {
  char title[50];
  char artist[50];
  char album[50];
  char year[10];
  char genre[20];
};

// function to extract metadata information from a file
struct MetaInfo* extractMetadata(char* filename) {
  // opening the file in read mode
  FILE* fp = fopen(filename, "r");
  if (fp == NULL) {
    printf("Error: could not open file.\n");
    exit(1);
  }

  // allocating memory for the metadata structure
  struct MetaInfo* info = (struct MetaInfo*) calloc(1, sizeof(struct MetaInfo));

  // reading the file line by line
  char line[100];
  while (fgets(line, sizeof(line), fp)) {
    // searching for metadata tags in each line
    if (strstr(line, "Title:") != NULL) {
      strncpy(info->title, line + 6, strlen(line) - 7);
    }
    else if (strstr(line, "Artist:") != NULL) {
      strncpy(info->artist, line + 7, strlen(line) - 8);
    }
    else if (strstr(line, "Album:") != NULL) {
      strncpy(info->album, line + 6, strlen(line) - 7);
    }
    else if (strstr(line, "Year:") != NULL) {
      strncpy(info->year, line + 5, strlen(line) - 6);
    }
    else if (strstr(line, "Genre:") != NULL) {
      strncpy(info->genre, line + 6, strlen(line) - 7);
    }
  }

  // closing the file
  fclose(fp);

  // returning the metadata structure
  return info;
}

// example usage of the metadata extractor function
int main() {
  // extracting metadata from a sample file
  struct MetaInfo* info = extractMetadata("sample.mp3");

  // print the extracted metadata
  printf("Title: %s\n", info->title);
  printf("Artist: %s\n", info->artist);
  printf("Album: %s\n", info->album);
  printf("Year: %s\n", info->year);
  printf("Genre: %s\n", info->genre);

  // freeing the allocated memory
  free(info);
  return 0;
}