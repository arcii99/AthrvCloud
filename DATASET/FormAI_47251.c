//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

int main() {

   FILE *file_pointer;
   char metadata[1000];

   file_pointer = fopen("example.mp3", "r");

   fseek(file_pointer, -128, SEEK_END);

   fread(metadata, sizeof(char), 128, file_pointer);

   printf("Title: %.*s\n", 30, metadata+3);
   printf("Artist: %.*s\n", 30, metadata+33);
   printf("Album: %.*s\n", 30, metadata+63);
   printf("Year: %.*s\n", 4, metadata+93);

   fclose(file_pointer);

   return 0;
}