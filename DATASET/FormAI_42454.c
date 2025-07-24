//FormAI DATASET v1.0 Category: Audio processing ; Style: excited
#include <stdio.h>
#include <stdlib.h>

#define SAMPLE_RATE 44100
#define BUFFER_SIZE 512
#define MAX_AMPLITUDE 32767

typedef struct {
  short left;
  short right;
} Sample;

int main() {
  
  printf("Welcome to the Audio Processor!\n");

  // Allocate memory for buffer
  Sample* buffer = (Sample*) malloc(BUFFER_SIZE * sizeof(Sample));

  if(buffer == NULL) {
    printf("Failed to allocate memory for buffer.\n");
    return 1;
  }

  // Generate white noise and fill buffer
  for(int i = 0; i < BUFFER_SIZE; i++) {
    buffer[i].left = rand() % MAX_AMPLITUDE; // generate random amplitude between 0 and MAX_AMPLITUDE
    buffer[i].right = rand() % MAX_AMPLITUDE;
  }

  printf("Buffer generated with white noise.\n");

  // Write buffer to file
  FILE* file = fopen("output.pcm", "wb");

  if(file == NULL) {
    printf("Failed to open file for writing.\n");
    return 1;
  }

  fwrite(buffer, sizeof(Sample), BUFFER_SIZE, file);

  printf("Buffer written to file.\n");

  // Read buffer from file
  fseek(file, 0, SEEK_SET); // move file pointer to beginning
  Sample* buffer2 = (Sample*) malloc(BUFFER_SIZE * sizeof(Sample));

  if(buffer2 == NULL) {
    printf("Failed to allocate memory for buffer2.\n");
    return 1;
  }

  fread(buffer2, sizeof(Sample), BUFFER_SIZE, file); 

  printf("Buffer read from file.\n");

  // Apply low-pass filter to buffer2
  float a = 0.9;
  float b = 0.1;
  short prev_left = 0;
  short prev_right = 0;

  for(int i = 0; i < BUFFER_SIZE; i++) {
    buffer2[i].left = a * buffer2[i].left + b * prev_left;
    buffer2[i].right = a * buffer2[i].right + b * prev_right;
    prev_left = buffer2[i].left;
    prev_right = buffer2[i].right;
  }

  printf("Low-pass filter applied to buffer2.\n");

  // Write filtered buffer to file
  FILE* file2 = fopen("output2.pcm", "wb");

  if(file2 == NULL) {
    printf("Failed to open file2 for writing.\n");
    return 1;
  }

  fwrite(buffer2, sizeof(Sample), BUFFER_SIZE, file2);

  printf("Filtered buffer written to file2.\n");

  // Free memory
  free(buffer);
  free(buffer2);

  printf("Memory freed.\n");

  // Close files
  fclose(file);
  fclose(file2);

  printf("Files closed.\n");

  printf("Program completed successfully!\n");

  return 0;
}