//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

// Function to convert the given string to binary format
char *strToBin(char *str) {
  int len = strlen(str);
  char *bin = (char *)calloc(len * 8, sizeof(char));

  for (int i = 0; i < len; ++i) {
    int val = str[i];
    int k = 0;
    while (k < 8) {
      *(bin + i * 8 + k) = ((val & 128) == 128) ? '1' : '0';
      val <<= 1;
      ++k;
    }
  }

  return bin;
}

// Function to convert the given binary string to decimal format
int binToInt(char *bin) {
  int decimal = 0;
  int len = strlen(bin);

  for (int i = 0; i < len; ++i) {
    decimal = decimal * 2 + bin[i] - '0';
  }

  return decimal;
}

// Function to embed the watermark in the given image
void embedWatermark(char *watermark, char *filename) {
  FILE *img = fopen(filename, "rb+");
  if (img == NULL) {
    printf("Unable to open file: %s\n", filename);
    return;
  }

  // Determine length of watermark in bits
  int watermark_len = strlen(watermark) * 8;

  // Determine the length of the image file
  fseek(img, 0, SEEK_END);
  int img_len = ftell(img);
  fseek(img, 0, SEEK_SET);

  int header_size = 54;  // 54 byte header present in all BMP files

  int padding = (4 - (img_len - header_size) % 4) % 4;
  
  // Calculate number of bytes available to store the watermark
  int watermark_space = (img_len - header_size - padding) / 8;

  // Check if the watermark can be embedded in the given image
  if (watermark_len > watermark_space) {
    printf("Watermark too large to be embedded in this image\n");
    fclose(img);
    return;
  }

  // Load the image header
  unsigned char header[header_size];
  fread(header, sizeof(unsigned char), header_size, img);
  fseek(img, header_size, SEEK_SET);

  // Embed the watermark
  int bit_index = 0;
  int byte_index = 0;
  while (bit_index < watermark_len) {
    char byte[MAX_SIZE] = {0};
    fread(byte, sizeof(char), 1, img);

    char *byte_bin = strToBin(byte);
    byte_bin[7] = watermark[bit_index++];

    int new_byte = binToInt(byte_bin);
    fseek(img, -1, SEEK_CUR);
    fwrite(&new_byte, sizeof(new_byte), 1, img);

    free(byte_bin);

    if (bit_index % 8 == 0) ++byte_index;
  }

  fclose(img);
}

// Function to extract the watermark from the given image
char *extractWatermark(char *filename, int watermark_len) {
  FILE *img = fopen(filename, "rb");
  if (img == NULL) {
    printf("Unable to open file: %s\n", filename);
    return NULL;
  }

  // Determine the length of the image file
  fseek(img, 0, SEEK_END);
  int img_len = ftell(img);
  fseek(img, 0, SEEK_SET);

  int header_size = 54;  // 54 byte header present in all BMP files

  int padding = (4 - (img_len - header_size) % 4) % 4;
  
  // Calculate number of bytes available that might contain the watermark
  int possible_len = (img_len - header_size - padding) / 8;

  // Check if the given watermark length is valid for the given image
  if (watermark_len > possible_len) {
    printf("Invalid watermark length for this image\n");
    fclose(img);
    return NULL;
  }

  // Load the image header
  unsigned char header[header_size];
  fread(header, sizeof(unsigned char), header_size, img);
  fseek(img, header_size, SEEK_SET);

  // Extract the watermark
  char *watermark = (char *)calloc(watermark_len + 1, sizeof(char));
  int bit_index = 0;
  int byte_index = 0;
  while (bit_index < watermark_len) {
    char byte[MAX_SIZE] = {0};
    fread(byte, sizeof(char), 1, img);

    char *byte_bin = strToBin(byte);
    watermark[bit_index++] = byte_bin[7];
    free(byte_bin);

    if (bit_index % 8 == 0) ++byte_index;
  }

  fclose(img);

  return watermark;
}

int main() {
  char *filename = "image.bmp";

  char *watermark = "This is a digital watermarking example.";
  printf("Embedding watermark in %s...\n", filename);
  embedWatermark(watermark, filename);

  printf("Extracting watermark from %s...\n", filename);
  char *extracted_watermark = extractWatermark(filename, strlen(watermark) * 8);
  printf("Extracted watermark: %s\n", extracted_watermark);

  free(extracted_watermark);

  return 0;
}