//FormAI DATASET v1.0 Category: Audio processing ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define BUFFER_SIZE 44100

int main()
{
    srand(time(0));
    float input_buffer[BUFFER_SIZE];
    int i;
    for(i=0; i<BUFFER_SIZE; i++)
    {
        input_buffer[i] = (float)rand()/(float)(RAND_MAX/2) - 1.0; // random signal between -1 and 1
    }

    // Processing the signal
    float output_buffer[BUFFER_SIZE];
    for(i=0; i<BUFFER_SIZE; i++)
    {
        output_buffer[i] = sin(input_buffer[i] * 2 * M_PI); // applying sine function
    }

    // Writing the output to a file
    FILE *fp = fopen("output_audio.wav", "wb");
    const char* chunk_id = "RIFF";
    const int chunk_size = 36 + BUFFER_SIZE*sizeof(float);
    const char* format = "WAVE";
    const char* subchunk1_id = "fmt ";
    const int subchunk1_size = 16;
    const short audio_format = 3;
    const short num_channels = 1;
    const int sample_rate = 44100;
    const int byte_rate = sample_rate * num_channels * sizeof(float);
    const short block_align = num_channels * sizeof(float);
    const short bits_per_sample = 8*sizeof(float);
    const char* subchunk2_id = "data";
    const int subchunk2_size = BUFFER_SIZE*sizeof(float);
    fwrite(chunk_id, 1, 4, fp);
    fwrite(&chunk_size, 4, 1, fp);
    fwrite(format, 1, 4, fp);
    fwrite(subchunk1_id, 1, 4, fp);
    fwrite(&subchunk1_size, 4, 1, fp);
    fwrite(&audio_format, 2, 1, fp);
    fwrite(&num_channels, 2, 1, fp);
    fwrite(&sample_rate, 4, 1, fp);
    fwrite(&byte_rate, 4, 1, fp);
    fwrite(&block_align, 2, 1, fp);
    fwrite(&bits_per_sample, 2, 1, fp);
    fwrite(subchunk2_id, 1, 4, fp);
    fwrite(&subchunk2_size, 4, 1, fp);
    fwrite(output_buffer, sizeof(float), BUFFER_SIZE, fp);
    fclose(fp);

    return 0;
}