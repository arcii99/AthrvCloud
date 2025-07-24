//FormAI DATASET v1.0 Category: Data recovery tool ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char file_name[50];
  int file_size;
  char file_data[1000];
} Data;

Data* recover_data(char* filename){
  FILE* fp = fopen(filename, "rb");
  if (fp == NULL) {
    printf("Unable to open file!");
    exit(EXIT_FAILURE);
  }

  fseek(fp, 0, SEEK_END);
  int file_size = ftell(fp);
  rewind(fp);

  Data* data = (Data*) malloc(sizeof(Data));
  strcpy(data->file_name, filename);
  data->file_size = file_size;

  fread(data->file_data, sizeof(char), file_size, fp);
  fclose(fp);

  return data;
}

int main() {
  char* filename = "data.bin"; // Example input file name
  Data* data = recover_data(filename);

  printf("Successfully read %d bytes from file: %s\n\n", data->file_size, data->file_name);

  // Further processing of the recovered data can be done here

  free(data);
  return 0;
}