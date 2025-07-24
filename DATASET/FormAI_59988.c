//FormAI DATASET v1.0 Category: Audio processing ; Style: scientific
/* Audio Processing Example Program */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define FREQUENCY 500

int main() {

    /* Generate sine wave with frequency 500 Hz */
    short buffer[SAMPLE_RATE];
    for (int i = 0; i < SAMPLE_RATE; i++) {
        buffer[i] = (short)(32767 * sin(2 * M_PI * FREQUENCY * i / SAMPLE_RATE));
    }

    /* Write audio data to file */
    FILE *output_file = fopen("audio.wav", "wb+");
    if (output_file == NULL) {
        printf("Error creating file.\n");
        exit(1);
    }

    /* WAV file header */
    char chunk_id[4] = {'R', 'I', 'F', 'F'};
    int chunk_size = SAMPLE_RATE * 2;
    char format[4] = {'W', 'A', 'V', 'E'};
    char subchunk1_id[4] = {'f', 'm', 't', ' '};
    int subchunk1_size = 16;
    short audio_format = 1;
    short num_channels = 1;
    int sample_rate = SAMPLE_RATE;
    int byte_rate = SAMPLE_RATE * 2;
    short block_align = 2;
    short bits_per_sample = 16;
    char subchunk2_id[4] = {'d', 'a', 't', 'a'};
    int subchunk2_size = SAMPLE_RATE * 2;

    /* Write header to file */
    fwrite(chunk_id, 1, 4, output_file);
    fwrite(&chunk_size, 4, 1, output_file);
    fwrite(format, 1, 4, output_file);
    fwrite(subchunk1_id, 1, 4, output_file);
    fwrite(&subchunk1_size, 4, 1, output_file);
    fwrite(&audio_format, 2, 1, output_file);
    fwrite(&num_channels, 2, 1, output_file);
    fwrite(&sample_rate, 4, 1, output_file);
    fwrite(&byte_rate, 4, 1, output_file);
    fwrite(&block_align, 2, 1, output_file);
    fwrite(&bits_per_sample, 2, 1, output_file);
    fwrite(subchunk2_id, 1, 4, output_file);
    fwrite(&subchunk2_size, 4, 1, output_file);

    /* Write audio data to file */
    fwrite(buffer, 2, SAMPLE_RATE, output_file);

    /* Close file */
    fclose(output_file);

    return 0;
}