//FormAI DATASET v1.0 Category: Image Steganography ; Style: Cryptic
/* Hiding secret message within an image using C Image Steganography */
/* Encrypts using cryptic algorithm */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 100000
#define MAXCHAR 200

// Function to read image data
void readImage(char* filename, int w, int h, int* image) {
  FILE* fp = fopen(filename, "r");
  if (!fp) {
    printf("Error opening file\n");
    exit(1);
  }
  char buff[MAXCHAR];
  fgets(buff, MAXCHAR, fp);
  fgets(buff, MAXCHAR, fp);

  fscanf(fp, "%d %d\n", &w, &h);
  fgets(buff, MAXCHAR, fp);

  int i = 0;
  int val, r, g, b;
  while (fgets(buff, MAXCHAR, fp)) {
    if (isdigit(buff[0])) {
      sscanf(buff, "%d %d %d %d", &i, &val, &val, &val);
      r = (val >> 16) & 0xff;
      g = (val >> 8) & 0xff;
      b = val & 0xff;
      image[i*3 + 0] = r & 0xfe;
      image[i*3 + 1] = g & 0xfe;
      image[i*3 + 2] = b & 0xfe;
    }
  }
  fclose(fp);
}

// Function to write image data
void writeImage(char* filename, int w, int h, int* image) {
  FILE* fp = fopen(filename, "w");
  if (!fp) {
    printf("Error opening file\n");
    exit(1);
  }

  fprintf(fp, "P3\n%d %d\n255\n", w, h);
  for (int i = 0; i < w*h; i++) {
    fprintf(fp, "%d %d %d\n", image[i*3 + 0], image[i*3 + 1], image[i*3 + 2]);
  }
  fclose(fp);
}

// Function to hide message within image
void hideMessage(char* filename, char* message) {
  int w = 0, h = 0;
  int* image = (int*)calloc(MAX, sizeof(int));
  readImage(filename, w, h, image);

  int ascii_vals[strlen(message)];
  for (int i = 0; i < strlen(message); i++) {
    ascii_vals[i] = message[i];
  }

  int i = 0, j = 0;
  int c, x;
  while (i < strlen(message)) {
    if (j % 3 == 0) {
      c = ascii_vals[i];
      i++;
    }

    x = (c >> (j % 3) * 2) & 0x03;

    image[j] |= x;
    j++;
  }

  writeImage(filename, w, h, image);
  free(image);
}

// Function to recover message from image
void recoverMessage(char* filename, char* message) {
  int w = 0, h = 0;
  int* image = (int*)calloc(MAX, sizeof(int));
  readImage(filename, w, h, image);

  int i = 0, j = 0, c = 0;
  while (j < 8 * strlen(message)) {
    c |= (image[j] & 0x03) << (j % 3) * 2;
    if (j % 3 == 2) {
      message[i] = (char)c;
      i++;
      c = 0;
    }
    j++;
  }

  free(image);
}

int main(int argc, char** argv) {
  if (argc < 3) {
    printf("Usage: ./steg -h <filename> <message> OR ./steg -r <filename>\n");
    exit(0);
  }

  char* filename = argv[2];
  char* message = (char*)calloc(MAX, sizeof(char));

  if (strcmp(argv[1], "-h") == 0) {
    for (int i = 0; i < strlen(argv[3]); i++) {
      message[i] = argv[3][i] + 20; // encrypt message using cryptic algorithm
    }
    hideMessage(filename, message);
    printf("Message hidden successfully\n");
  }
  else if (strcmp(argv[1], "-r") == 0) {
    recoverMessage(filename, message);
    printf("Recovered message: ");
    for (int i = 0; i < strlen(message); i++) {
      printf("%c", message[i] - 20); // decrypt message using cryptic algorithm
    }
    printf("\n");
  }
  else {
    printf("Invalid option\n");
  }

  free(message);
  return 0;
}