//FormAI DATASET v1.0 Category: Image Editor ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

// function to read image file
void read_image(unsigned char image[][512], char *filename) {
  FILE *fp;
  fp = fopen(filename, "rb");

  if (fp == NULL) {
    printf("Error opening image file.\n");
    exit(1);
  }

  fread(image, sizeof(unsigned char), 512*512, fp);
  fclose(fp);
}

// function to write image file
void write_image(unsigned char image[][512], char *filename) {
  FILE *fp;
  fp = fopen(filename, "wb");

  if (fp == NULL) {
    printf("Error creating image file.\n");
    exit(1);
  }

  fwrite(image, sizeof(unsigned char), 512*512, fp);
  fclose(fp);
}

// function to flip image horizontally
void flip_horizontal(unsigned char image[][512]) {
  int i, j;
  unsigned char temp;

  for (i = 0; i < 512; i++) {
    for (j = 0; j < 256; j++) {
      temp = image[i][j];
      image[i][j] = image[i][511-j];
      image[i][511-j] = temp;
    }
  }
}

// function to flip image vertically
void flip_vertical(unsigned char image[][512]) {
  int i, j;
  unsigned char temp;

  for (i = 0; i < 256; i++) {
    for (j = 0; j < 512; j++) {
      temp = image[i][j];
      image[i][j] = image[511-i][j];
      image[511-i][j] = temp;
    }
  }
}

// function to rotate image by 90 degrees
void rotate_90(unsigned char image[][512]) {
  int i, j;
  unsigned char temp;

  // transpose matrix
  for (i = 0; i < 512; i++) {
    for (j = i+1; j < 512; j++) {
      temp = image[i][j];
      image[i][j] = image[j][i];
      image[j][i] = temp;
    }
  }

  // flip horizontally
  flip_horizontal(image);
}

int main(int argc, char *argv[]) {
  unsigned char image[512][512];

  if (argc != 3) {
    printf("Incorrect number of arguments.\n");
    printf("Usage: image_editor <infile> <outfile>\n");
    exit(1);
  }

  // read image file
  read_image(image, argv[1]);

  // perform transformations
  flip_horizontal(image);
  flip_vertical(image);
  rotate_90(image);

  // write transformed image to file
  write_image(image, argv[2]);

  return 0;
}