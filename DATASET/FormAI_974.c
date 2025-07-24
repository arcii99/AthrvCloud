//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define a structure to hold metadata information */
typedef struct {
  char* title;
  char* artist;
  char* album;
  int year;
  int trackNum;
} Metadata;

/* Function to extract metadata from a file */
void extractMetadata(char* filePath, Metadata* data) {
  FILE* fp = fopen(filePath, "r");
  if (fp == NULL) {
    printf("Unable to open file for reading.\n");
    return;
  }

  char line[1024];
  while (fgets(line, 1024, fp)) {
    if (strncmp(line, "Title:", 6) == 0) {
      data->title = strdup(line + 7);
      data->title[strcspn(data->title, "\r\n")] = '\0'; // Remove newline characters
    } else if (strncmp(line, "Artist:", 7) == 0) {
      data->artist = strdup(line + 8);
      data->artist[strcspn(data->artist, "\r\n")] = '\0'; // Remove newline characters
    } else if (strncmp(line, "Album:", 6) == 0) {
      data->album = strdup(line + 7);
      data->album[strcspn(data->album, "\r\n")] = '\0'; // Remove newline characters
    } else if (strncmp(line, "Year:", 5) == 0) {
      sscanf(line + 6, "%d", &data->year);
    } else if (strncmp(line, "Track:", 6) == 0) {
      sscanf(line + 7, "%d", &data->trackNum);
    }
  }

  fclose(fp);
}

/****************** MAIN PROGRAM ******************/

int main(int argc, char* argv[]) {
  if (argc != 2) {
    printf("Usage: %s <file path>\n", argv[0]);
    return 1;
  }

  Metadata data;
  memset(&data, 0, sizeof(Metadata)); // Initialize all fields to 0

  extractMetadata(argv[1], &data);

  printf("Title: %s\n", data.title);
  printf("Artist: %s\n", data.artist);
  printf("Album: %s\n", data.album);
  printf("Year: %d\n", data.year);
  printf("Track Number: %d\n", data.trackNum);

  free(data.title);
  free(data.artist);
  free(data.album);

  return 0;
}