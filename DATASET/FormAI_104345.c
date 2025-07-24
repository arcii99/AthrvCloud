//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>

// Define struct for storing metadata
typedef struct metadata {
  char artist[50];
  char song_title[50];
  char album[50];
  int year;
} Metadata;

int main() {
  // Initialize metadata object
  Metadata data;

  // Read in metadata from file
  FILE *fp = fopen("song.mp3", "rb");
  fseek(fp, -128, SEEK_END); // ID3 tag located at end of file
  char buffer[128];
  fread(buffer, sizeof(buffer), 1, fp);
  fclose(fp);

  // Parse metadata from buffer
  strncpy(data.song_title, buffer+3, 30);
  strncpy(data.artist, buffer+33, 30);
  strncpy(data.album, buffer+63, 30);
  sscanf(buffer+93, "%d", &data.year);

  // Output extracted metadata
  printf("Title: %s\n", data.song_title);
  printf("Artist: %s\n", data.artist);
  printf("Album: %s\n", data.album);
  printf("Year: %d\n", data.year);

  return 0;
}