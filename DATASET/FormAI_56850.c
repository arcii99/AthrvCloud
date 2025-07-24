//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define BLOCKSIZE 1024

// Function to embed the watermark
void embedWatermark(char* audioFile, char* watermark) {
  FILE* in = fopen(audioFile, "rb");
  FILE* out = fopen("watermarkedAudio.wav", "wb");
  char buf[BLOCKSIZE];
  int count = 0;
  int watermarkIndex = 0;

  // Copy the header data
  while (count < 44) {
    fread(buf, sizeof(char), 1, in);
    fwrite(buf, sizeof(char), 1, out);
    count++;
  }

  // Embed the watermark into the audio data
  while (fread(buf, sizeof(char), BLOCKSIZE, in) > 0) {
    for (int i = 0; i < BLOCKSIZE; i++) {
      if (watermarkIndex >= strlen(watermark)) {
        break;
      }
      int bit = (watermark[watermarkIndex] >> (i % 8)) & 1;
      buf[i] = (buf[i] & 0xFE) | bit;
      watermarkIndex++;
    }
    fwrite(buf, sizeof(char), BLOCKSIZE, out);
  }

  // Copy the rest of the file
  while (fread(buf, sizeof(char), BLOCKSIZE, in) > 0) {
    fwrite(buf, sizeof(char), BLOCKSIZE, out);
  }

  printf("Watermark embedded successfully!\n");

  fclose(in);
  fclose(out);
}

// Function to detect the watermark
void detectWatermark(char* audioFile) {
  FILE* in = fopen(audioFile, "rb");
  char buf[BLOCKSIZE];
  int count = 0;
  int watermarkIndex = 0;
  int watermarkLength = 0;

  // Skip over the header data
  while (count < 44) {
    fread(buf, sizeof(char), 1, in);
    count++;
  }

  // Determine the length of the watermark
  fread(buf, sizeof(char), BLOCKSIZE, in);
  for (int i = 0; i < BLOCKSIZE; i++) {
    watermarkLength = watermarkLength | ((buf[i] & 1) << (i % 8));
    if ((i + 1) % 8 == 0) {
      if (watermarkLength == 0) {
        break;
      }
    }
  }

  char* watermark = malloc(watermarkLength);
  memset(watermark, 0, watermarkLength);

  // Extract the watermark from the audio data
  while (fread(buf, sizeof(char), BLOCKSIZE, in) > 0) {
    for (int i = 0; i < BLOCKSIZE; i++) {
      if (watermarkIndex >= watermarkLength) {
        break;
      }
      watermark[watermarkIndex] = (watermark[watermarkIndex] & 0xFE) | (buf[i] & 1);
      watermarkIndex++;
    }
    if (watermarkIndex >= watermarkLength) {
      break;
    }
  }

  printf("Watermark detected: %s\n", watermark);

  fclose(in);
}

int main(int argc, char** argv) {
  if (argc == 2) {
    detectWatermark(argv[1]);
  }
  else if (argc == 3) {
    embedWatermark(argv[1], argv[2]);
  }
  else {
    printf("Usage: watermark [audioFile] [watermark]\n");
  }

  return 0;
}