//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int scan_file(char* file_path) {
  FILE* file = fopen(file_path, "rb");

  // Check if file exists and can be opened
  if (!file) {
    printf("[ERROR] Unable to open file: %s\n", file_path);
    return -1;
  }

  // Get file size in bytes
  fseek(file, 0, SEEK_END);
  long int file_size = ftell(file);
  fseek(file, 0, SEEK_SET);

  // Read file contents
  char* file_contents = malloc(file_size);
  fread(file_contents, 1, file_size, file);

  // Close file
  fclose(file);

  // Look for virus signature
  char* virus_signature = "malware_code";
  if (strstr(file_contents, virus_signature)) {
    printf("[WARNING] Virus found in file: %s\n", file_path);
    return 1;
  }

  // Virus not found
  return 0;
}

int main(int argc, char** argv) {
  char* file_path = argv[1];
  int result = scan_file(file_path);

  if (result == 0) {
    printf("[INFO] File is clean: %s\n", file_path);
  }

  return 0;
}