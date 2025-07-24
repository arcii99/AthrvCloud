//FormAI DATASET v1.0 Category: Data recovery tool ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the struct for file metadata
typedef struct file_meta_t {
  char* filename;
  char* extension;
  int size;
  char* content;
} file_meta;

// Function to read file metadata from a binary data file
void read_file_meta(file_meta* current_file, FILE* binary_file) {
  // First, determine the filename length
  int filename_length;
  fread(&filename_length, sizeof(int), 1, binary_file);

  // Allocate memory for the filename and read it from the file
  current_file->filename = malloc(filename_length);
  fread(current_file->filename, sizeof(char), filename_length, binary_file);

  // Determine the extension length and repeat for the extension
  int ext_length;
  fread(&ext_length, sizeof(int), 1, binary_file);
  current_file->extension = malloc(ext_length);
  fread(current_file->extension, sizeof(char), ext_length, binary_file);

  // Read the size of the file and allocate memory for the content
  fread(&current_file->size, sizeof(int), 1, binary_file);
  current_file->content = malloc(current_file->size);

  // Finally, read the content of the file
  fread(current_file->content, sizeof(char), current_file->size, binary_file);
}

int main() {
  // Initialize the list of recovered files
  file_meta* recovered_files = malloc(sizeof(file_meta) * 10);
  int num_recovered_files = 0;

  // Open the binary file containing the lost data
  FILE* recovery_file = fopen("data_recovery.bin", "rb");
  
  // Loop through the binary file and attempt to recover any files
  while (!feof(recovery_file)) {
    // Create a new file_meta struct for the current file
    file_meta current_file;

    // Attempt to read the metadata for the file, skipping any empty records
    if (fread(&current_file.size, sizeof(int), 1, recovery_file)) {
      read_file_meta(&current_file, recovery_file);

      // Check if the file has a valid size and content
      if (current_file.size != strlen(current_file.content)) {
        printf("File %s.%s is corrupted and cannot be recovered\n", current_file.filename, current_file.extension);
      } else {
        // Add the file to the list of recovered files
        recovered_files[num_recovered_files] = current_file;
        num_recovered_files++;
      }
    } else {
      // Skip over any empty records
      fseek(recovery_file, sizeof(int) * 3, SEEK_CUR);
    }
  }

  // Display the list of recovered files
  printf("%d files have been recovered:\n", num_recovered_files);
  for (int i = 0; i < num_recovered_files; i++) {
    printf("- %s.%s (%d bytes)\n", recovered_files[i].filename, recovered_files[i].extension, recovered_files[i].size);
  }

  // Close the recovery file and free any memory
  fclose(recovery_file);
  for (int i = 0; i < num_recovered_files; i++) {
    free(recovered_files[i].filename);
    free(recovered_files[i].extension);
    free(recovered_files[i].content);
  }
  free(recovered_files);

  return 0;
}