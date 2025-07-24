//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct metadata {
  char *title;
  char *artist;
  char *album;
  int year;
} Metadata;

void extractTitle(char *line, Metadata *metadata);
void extractArtist(char *line, Metadata *metadata);
void extractAlbum(char *line, Metadata *metadata);
void extractYear(char *line, Metadata *metadata);
void printMetadata(Metadata *metadata);

int main() {
  char line[100];
  Metadata metadata = {"Unknown Title", "Unknown Artist", "Unknown Album", 0000};
  FILE *fp = fopen("song.mp3", "r");

  if (fp == NULL) {
    printf("Error: Failed to open file\n");
    exit(1);
  }

  while (fgets(line, sizeof(line), fp)) {
    if (strstr(line, "TIT2") != NULL) {
      extractTitle(line, &metadata);
    }
    if (strstr(line, "TPE1") != NULL) {
      extractArtist(line, &metadata);
    }
    if (strstr(line, "TALB") != NULL) {
      extractAlbum(line, &metadata);
    }
    if (strstr(line, "TYER") != NULL) {
      extractYear(line, &metadata);
    }
  }

  fclose(fp);
  printMetadata(&metadata);

  return 0;
}

void extractTitle(char *line, Metadata *metadata) {
  char *token = strtok(line, "=");
  metadata->title = strtok(NULL, "=");
}

void extractArtist(char *line, Metadata *metadata) {
  char *token = strtok(line, "=");
  metadata->artist = strtok(NULL, "=");
}

void extractAlbum(char *line, Metadata *metadata) {
  char *token = strtok(line, "=");
  metadata->album = strtok(NULL, "=");
}

void extractYear(char *line, Metadata *metadata) {
  char *token = strtok(line, "=");
  metadata->year = atoi(strtok(NULL, "="));
}

void printMetadata(Metadata *metadata) {
  printf("Title: %s\n", metadata->title);
  printf("Artist: %s\n", metadata->artist);
  printf("Album: %s\n", metadata->album);
  printf("Year: %d\n", metadata->year);
}