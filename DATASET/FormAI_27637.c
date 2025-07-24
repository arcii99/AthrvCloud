//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct metadata {
  char* title;
  char* artist;
  char* album;
  int year;
  int bitrate;
  double duration;
} Metadata;

void extract_from_file(const char* filename, Metadata* metadata) {
  // Open file
  FILE* file = fopen(filename, "rb");
  if (!file) {
    fprintf(stderr, "Failed to open file: %s\n", filename);
    return;
  }

  // Read metadata
  char buffer[128];
  char* ptr = NULL;
  while (fgets(buffer, sizeof(buffer), file)) {
    if ((ptr = strstr(buffer, "Title:")) != NULL) {
      metadata->title = strdup(ptr + 7);
      metadata->title[strlen(metadata->title)-1] = '\0'; // Remove newline
    }
    else if ((ptr = strstr(buffer, "Artist:")) != NULL) {
      metadata->artist = strdup(ptr + 8);
      metadata->artist[strlen(metadata->artist)-1] = '\0'; // Remove newline
    }
    else if ((ptr = strstr(buffer, "Album:")) != NULL) {
      metadata->album = strdup(ptr + 7);
      metadata->album[strlen(metadata->album)-1] = '\0'; // Remove newline
    }
    else if ((ptr = strstr(buffer, "Year:")) != NULL) {
      metadata->year = atoi(ptr + 6);
    }
    else if ((ptr = strstr(buffer, "Bitrate:")) != NULL) {
      metadata->bitrate = atoi(ptr + 9);
    }
    else if ((ptr = strstr(buffer, "Duration:")) != NULL) {
      metadata->duration = atof(ptr + 10);
    }
  }

  // Close file
  fclose(file);
}

int main(int argc, char* argv[]) {
  // Check arguments
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
    return 1;
  }

  // Extract metadata
  Metadata metadata;
  memset(&metadata, 0, sizeof(metadata));
  extract_from_file(argv[1], &metadata);

  // Print metadata
  printf("Title:   %s\n", metadata.title);
  printf("Artist:  %s\n", metadata.artist);
  printf("Album:   %s\n", metadata.album);
  printf("Year:    %d\n", metadata.year);
  printf("Bitrate: %d\n", metadata.bitrate);
  printf("Duration:%.2f\n", metadata.duration);

  // Free memory
  free(metadata.title);
  free(metadata.artist);
  free(metadata.album);

  return 0;
}