//FormAI DATASET v1.0 Category: File Encyptor ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  char* key = "secretkey";
  int key_length = strlen(key);
  char* buffer = (char*) malloc(sizeof(char)*1024);
  FILE* fp_in;
  FILE* fp_out;

  if(argc != 3) {
    printf("Usage: %s <input_file> <output_file>\n", argv[0]);
    return 1;
  }

  if((fp_in = fopen(argv[1], "r")) == NULL) {
    printf("Error: Could not open %s for read\n", argv[1]);
    return 1;
  }

  if((fp_out = fopen(argv[2], "w")) == NULL) {
    printf("Error: Could not open %s for write\n", argv[2]);
    return 1;
  }

  while(!feof(fp_in)) {
    int bytes_read = fread(buffer, sizeof(char), 1024, fp_in);
    for(int i = 0; i<bytes_read; i++) {
      buffer[i] ^= key[i%key_length];
    }
    fwrite(buffer, sizeof(char), bytes_read, fp_out);
  }

  fclose(fp_in);
  fclose(fp_out);
  return 0;
}