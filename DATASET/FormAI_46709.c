//FormAI DATASET v1.0 Category: Image Editor ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

// defining the maximum width and height of the image
#define MAX_WIDTH 256
#define MAX_HEIGHT 256

// defining the structure of the image
typedef struct {
  int width;
  int height;
  unsigned char data[MAX_HEIGHT][MAX_WIDTH][3];
} Image;

// function to read an image from a file
void readImage(char *filename, Image *img) {
  // open the input file
  FILE *fp = fopen(filename, "rb");
  if (fp == NULL) {
    fprintf(stderr, "Error: could not open input file %s.\n", filename);
    exit(1);
  }

  // read the image header
  fscanf(fp, "P6\n%d %d\n255\n", &img->width, &img->height);

  // read the image data
  int i, j;
  for (i = 0; i < img->height; i++) {
    for (j = 0; j < img->width; j++) {
      fread(img->data[i][j], 3, 1, fp);
    }
  }

  // close the input file
  fclose(fp);
}

// function to write an image to a file
void writeImage(char *filename, Image *img) {
  // open the output file
  FILE *fp = fopen(filename, "wb");
  if (fp == NULL) {
    fprintf(stderr, "Error: could not open output file %s.\n", filename);
    exit(1);
  }

  // write the image header
  fprintf(fp, "P6\n%d %d\n255\n", img->width, img->height);

  // write the image data
  int i, j;
  for (i = 0; i < img->height; i++) {
    for (j = 0; j < img->width; j++) {
      fwrite(img->data[i][j], 3, 1, fp);
    }
  }

  // close the output file
  fclose(fp);
}

// function to apply a grayscale filter to an image
void grayscale(Image *img) {
  int i, j;
  for (i = 0; i < img->height; i++) {
    for (j = 0; j < img->width; j++) {
      unsigned char r = img->data[i][j][0];
      unsigned char g = img->data[i][j][1];
      unsigned char b = img->data[i][j][2];
      unsigned char gray = 0.2126 * r + 0.7152 * g + 0.0722 * b;
      img->data[i][j][0] = gray;
      img->data[i][j][1] = gray;
      img->data[i][j][2] = gray;
    }
  }
}

// function to apply a blur filter to an image
void blur(Image *img) {
  int i, j, k, l;
  unsigned char newData[MAX_HEIGHT][MAX_WIDTH][3];
  for (i = 0; i < img->height; i++) {
    for (j = 0; j < img->width; j++) {
      int count = 1;
      unsigned int r = img->data[i][j][0];
      unsigned int g = img->data[i][j][1];
      unsigned int b = img->data[i][j][2];
      for (k = i - 1; k <= i + 1; k++) {
        for (l = j - 1; l <= j + 1; l++) {
          if (k >= 0 && k < img->height && l >= 0 && l < img->width) {
            r += img->data[k][l][0];
            g += img->data[k][l][1];
            b += img->data[k][l][2];
            count++;
          }
        }
      }
      newData[i][j][0] = r / count;
      newData[i][j][1] = g / count;
      newData[i][j][2] = b / count;
    }
  }
  for (i = 0; i < img->height; i++) {
    for (j = 0; j < img->width; j++) {
      img->data[i][j][0] = newData[i][j][0];
      img->data[i][j][1] = newData[i][j][1];
      img->data[i][j][2] = newData[i][j][2];
    }
  }
}

// function to apply a rotate filter to an image
void rotate(Image *img) {
  int i, j, k;
  unsigned char newData[MAX_HEIGHT][MAX_WIDTH][3];
  for (i = 0; i < img->height; i++) {
    for (j = 0; j < img->width; j++) {
      int x = img->height - i - 1;
      int y = j;
      newData[y][x][0] = img->data[i][j][0];
      newData[y][x][1] = img->data[i][j][1];
      newData[y][x][2] = img->data[i][j][2];
    }
  }
  int temp = img->width;
  img->width = img->height;
  img->height = temp;
  for (i = 0; i < img->height; i++) {
    for (j = 0; j < img->width; j++) {
      for (k = 0; k < 3; k++) {
        img->data[i][j][k] = newData[i][j][k];
      }
    }
  }
}

int main(int argc, char *argv[]) {
  // check for command line arguments
  if (argc != 4) {
    fprintf(stderr, "Usage: %s <input_file> <output_file> <filter>\n", argv[0]);
    fprintf(stderr, "Valid filters are: grayscale, blur, rotate.\n");
    exit(1);
  }

  // read the input image
  Image img;
  readImage(argv[1], &img);

  // apply the selected filter to the image
  if (strcmp(argv[3], "grayscale") == 0) {
    grayscale(&img);
  } else if (strcmp(argv[3], "blur") == 0) {
    blur(&img);
  } else if (strcmp(argv[3], "rotate") == 0) {
    rotate(&img);
  } else {
    fprintf(stderr, "Invalid filter specified.\n");
    fprintf(stderr, "Valid filters are: grayscale, blur, rotate.\n");
    exit(1);
  }

  // write the output image
  writeImage(argv[2], &img);

  return 0;
}