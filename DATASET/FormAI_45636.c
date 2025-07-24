//FormAI DATASET v1.0 Category: Audio processing ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define BUFFER_SIZE 48000

int main()
{
  float input[BUFFER_SIZE];
  float output[BUFFER_SIZE];
  float x[BUFFER_SIZE];
  float y[BUFFER_SIZE];

  // Generate a sine wave input signal
  for (int i = 0; i < BUFFER_SIZE; i++)
  {
    input[i] = sin(2 * M_PI * i / 48000 * 440);
  }

  // Add a low-pass filter
  float cutoff = 2000;
  float RC = 1 / (2 * M_PI * cutoff);
  float alpha = 1 / (RC + 1);
  x[0] = input[0];
  y[0] = 0;
  for (int i = 1; i < BUFFER_SIZE; i++)
  {
    x[i] = input[i] + alpha * (x[i-1] - input[i]);
    y[i] = y[i-1] + alpha * (x[i-1] - y[i-1]);
    output[i] = y[i];
  }

  // Normalize the output signal
  float maxval = 0;
  for (int i = 0; i < BUFFER_SIZE; i++)
  {
    if (fabs(output[i]) > maxval)
    {
      maxval = fabs(output[i]);
    }
  }
  for (int i = 0; i < BUFFER_SIZE; i++)
  {
    output[i] /= maxval;
  }

  // Save the output signal to a file
  FILE *fp;
  fp = fopen("output.wav", "wb");
  fprintf(fp, "RIFF");
  int filesize = BUFFER_SIZE * 2 + 36;
  fwrite(&filesize, 4, 1, fp);
  fprintf(fp, "WAVE");
  fprintf(fp, "fmt ");
  int fmtsize = 16;
  fwrite(&fmtsize, 4, 1, fp);
  int format = 1;
  fwrite(&format, 2, 1, fp);
  int channels = 1;
  fwrite(&channels, 2, 1, fp);
  int samplerate = 48000;
  fwrite(&samplerate, 4, 1, fp);
  int byterate = samplerate * 2;
  fwrite(&byterate, 4, 1, fp);
  int blockalign = 2;
  fwrite(&blockalign, 2, 1, fp);
  int bitspersample = 16;
  fwrite(&bitspersample, 2, 1, fp);
  fprintf(fp, "data");
  int datasize = BUFFER_SIZE * 2;
  fwrite(&datasize, 4, 1, fp);
  for (int i = 0; i < BUFFER_SIZE; i++)
  {
    short val = output[i] * 32767;
    fwrite(&val, 2, 1, fp);
  }
  fclose(fp);

  return 0;
}