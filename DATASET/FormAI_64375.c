//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main(int argc, char **argv) {
  if (argc < 3) {
    printf("Usage: watermark input_file output_file\n");
    return 1;
  }

  FILE *input_file = fopen(argv[1], "rb");
  FILE *output_file = fopen(argv[2], "wb");

  if (input_file == NULL || output_file == NULL) {
    printf("Error: Failed to open the input/output file.\n");
    return 1;
  }

  unsigned char buffer[BUFFER_SIZE];
  size_t watermark_size = strlen("Watermarked by John Doe");

  // Embed the digital watermark
  for (;;) {
    size_t bytes_read = fread(buffer, 1, BUFFER_SIZE, input_file);

    if (bytes_read == 0) {
      break;
    }

    // Embed the watermark at the end of the buffer
    memcpy(buffer + bytes_read, "Watermarked by John Doe", watermark_size);
    fwrite(buffer, 1, bytes_read + watermark_size, output_file);
  }

  fclose(input_file);
  fclose(output_file);

  return 0;
}