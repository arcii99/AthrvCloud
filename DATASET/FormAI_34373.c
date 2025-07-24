//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1000

typedef struct Metadata {
  char **data;
  int count;
} Metadata;

void free_metadata(Metadata *metadata) {
  int i;
  for(i = 0; i < metadata->count; i++) {
    free(metadata->data[i]);
  }
  if(metadata->count > 0) {
    free(metadata->data);
  }
  metadata->count = 0;
  metadata->data = NULL;
}

void parse_metadata(char *line, Metadata *metadata) {
  int i, j, k;
  char *token, *delim;
  delim = " \t\n\r";
  j = 0;
  k = 0;
  while(line[k]) {
    if(line[k] == '#') {
      break;
    }
    k++;
  }
  line[k] = '\0';
  i = 0;
  token = strtok(line, delim);
  while(token) {
    if(i >= metadata->count) {
      metadata->count += 50;
      metadata->data = realloc(metadata->data, metadata->count * sizeof(char *));
      if(metadata->data == NULL) {
        fprintf(stderr, "Error: Out of memory\n");
        exit(1);
      }
      memset(metadata->data + i, 0, 50 * sizeof(char *));
    }
    metadata->data[i++] = strdup(token);
    token = strtok(NULL, delim);
  }
}

int main(int argc, char **argv) {
  FILE *fp;
  char line[MAX_LINE_SIZE];
  Metadata metadata;
  metadata.count = 0;
  metadata.data = NULL;
  if(argc != 2) {
    fprintf(stderr, "usage: %s <filename>\n", argv[0]);
    exit(1);
  }
  fp = fopen(argv[1], "r");
  if(fp == NULL) {
    fprintf(stderr, "Error: Could not open file %s\n", argv[1]);
    exit(1);
  }
  while(fgets(line, MAX_LINE_SIZE, fp)) {
    if(line[0] == '\n' || line[0] == '\r') {
      continue;
    }
    parse_metadata(line, &metadata);
  }
  printf("%d pieces of metadata found\n", metadata.count);
  free_metadata(&metadata);
  fclose(fp);
  return 0;
}