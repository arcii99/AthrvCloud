//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  char file_name[50];
  char author_name[50];
  int file_size;
} File;

int main() {
  File extracted_file;
  printf("Enter file name: ");
  scanf("%s", extracted_file.file_name);
  printf("Enter author name: ");
  scanf("%s", extracted_file.author_name);
  printf("Enter file size (in KB): ");
  scanf("%d", &extracted_file.file_size);
  printf("\nExtraction successful! Here are the metadata details:\n\n");
  printf("File Name: %s\nAuthor Name: %s\nFile Size: %d KB\n", extracted_file.file_name, extracted_file.author_name, extracted_file.file_size);

  // post-apocalyptic twist
  printf("\nWarning: The extracted file may contain harmful viruses and could be the cause of the apocalypse. Proceed with caution!");
  return 0;
}