//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILENAME_LENGTH 50
#define MAX_BUFFER_LENGTH 1024

int main() {
  char input_filename[MAX_FILENAME_LENGTH], output_filename[MAX_FILENAME_LENGTH];
  FILE *input_file, *output_file;

  printf("Enter the input image file name: ");
  scanf("%s", input_filename);

  // Open the input file
  input_file = fopen(input_filename, "rb");
  if (input_file == NULL) {
    printf("Error: cannot open input file %s\n", input_filename);
    exit(1);
  }

  printf("Enter the output image file name: ");
  scanf("%s", output_filename);

  // Open the output file
  output_file = fopen(output_filename, "wb");
  if (output_file == NULL) {
    printf("Error: cannot open output file %s\n", output_filename);
    exit(1);
  }

  unsigned char header[54];
  size_t header_size = fread(header, 1, 54, input_file);
  if (header_size != 54) {
    printf("Error: invalid BMP header\n");
    exit(1);
  }

  int width, height;
  memcpy(&width, &header[18], sizeof(int));
  memcpy(&height, &header[22], sizeof(int));

  unsigned char *buffer = malloc(width * height * 3);
  size_t n_read = fread(buffer, 1, width * height * 3, input_file);
  if (n_read != width * height * 3) {
    printf("Error: invalid BMP pixel data\n");
    exit(1);
  }

  printf("Which would you like to do?\n");
  printf("1. Flip the image\n");
  printf("2. Adjust brightness and contrast\n");
  printf("> ");

  int option;
  scanf("%d", &option);

  switch (option) {
    case 1:
      // Flip the image horizontally
      for (int y = 0; y < height; y++) {
        for (int x = 0; x < width / 2; x++) {
          for (int c = 0; c < 3; c++) {
            unsigned char tmp = buffer[(y * width + x) * 3 + c];
            buffer[(y * width + x) * 3 + c] = buffer[(y * width + (width - x - 1)) * 3 + c];
            buffer[(y * width + (width - x - 1)) * 3 + c] = tmp;
          }
        }
      }
      break;

    case 2:
      // Adjust brightness and contrast
      int brightness, contrast;
      printf("Enter brightness adjustment (-255 to 255): ");
      scanf("%d", &brightness);
      printf("Enter contrast adjustment (-255 to 255): ");
      scanf("%d", &contrast);

      for (int i = 0; i < width * height * 3; i++) {
        int value = (int)buffer[i] + brightness;
        value = (int)((value - 128) * ((float)contrast / 128.0f) + 128);

        if (value < 0) {
          buffer[i] = 0;
        } else if (value > 255) {
          buffer[i] = 255;
        } else {
          buffer[i] = (unsigned char)value;
        }
      }
      break;

    default:
      printf("Error: invalid option selected\n");
      exit(1);
  }

  // Write the output file header
  fwrite(header, 1, 54, output_file);
  // Write the output file pixel data
  fwrite(buffer, 1, width * height * 3, output_file);

  // Close the files and free memory
  fclose(input_file);
  fclose(output_file);
  free(buffer);

  printf("Image processing complete. Output written to %s\n", output_filename);

  return 0;
}