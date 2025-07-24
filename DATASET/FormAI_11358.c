//FormAI DATASET v1.0 Category: Audio processing ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* define the number of audio samples */
#define SAMPLES 5000

/* define the number of audio channels */
#define CHANNELS 2

/* define the maximum amplitude value */
#define MAX_AMPLITUDE 32767

/* define the sample rate */
#define SAMPLE_RATE 44100

/* create an array to hold the audio samples */
short audio[SAMPLES][CHANNELS];

/* function to shift the audio samples down by a given amount */
void shift_down(int amount) {
    for (int i = 0; i < SAMPLES; i++) {
        for (int j = 0; j < CHANNELS; j++) {
            audio[i][j] = audio[i][j] / amount;
        }
    }
}

/* function to shift the audio samples up by a given amount */
void shift_up(int amount) {
    for (int i = 0; i < SAMPLES; i++) {
        for (int j = 0; j < CHANNELS; j++) {
            audio[i][j] = audio[i][j] * amount;
            if (audio[i][j] > MAX_AMPLITUDE) {
                audio[i][j] = MAX_AMPLITUDE;
            }
        }
    }
}

/* function to apply a low-pass filter to the audio samples */
void low_pass_filter(int cutoff_frequency, int order) {
    double alpha = 1.0 / (1.0 + cos(M_PI * cutoff_frequency / SAMPLE_RATE));
    double* coefficients = malloc((order + 1) * sizeof(double));
    double* previous_input_values = calloc(order, sizeof(double));
    double* previous_output_values = calloc(order, sizeof(double));
    for (int i = 0; i < order + 1; i++) {
        double coefficient = 0.0;
        if (i == 0) {
            coefficient = (1.0 - alpha) / 2.0;
        }
        else if (i == order) {
            coefficient = (1.0 - alpha) / 2.0;
        }
        else {
            coefficient = 1.0 - alpha;
        }
        coefficients[i] = coefficient;
    }
    for (int i = 0; i < SAMPLES; i++) {
        for (int j = 0; j < CHANNELS; j++) {
            double input_value = (double)audio[i][j] / MAX_AMPLITUDE;
            double output_value = 0.0;
            for (int k = 0; k < order; k++) {
                output_value += coefficients[k] * previous_input_values[k] - coefficients[k + 1] * previous_output_values[k];
            }
            output_value += coefficients[order] * input_value;
            audio[i][j] = (short)(output_value * MAX_AMPLITUDE);
            if (audio[i][j] > MAX_AMPLITUDE) {
                audio[i][j] = MAX_AMPLITUDE;
            }
            previous_input_values[0] = input_value;
            previous_output_values[0] = output_value;
            for (int k = order - 1; k > 0; k--) {
                previous_input_values[k] = previous_input_values[k - 1];
                previous_output_values[k] = previous_output_values[k - 1];
            }
        }
    }
    free(coefficients);
    free(previous_input_values);
    free(previous_output_values);
}

/* main function to generate and process audio */
int main() {
    /* generate a sine wave with a frequency of 440 Hz */
    for (int i = 0; i < SAMPLES; i++) {
        double t = (double)i / SAMPLE_RATE;
        audio[i][0] = (short)(MAX_AMPLITUDE * sin(2.0 * M_PI * 440.0 * t));
        audio[i][1] = audio[i][0];
    }
    
    /* apply effects to the audio */
    shift_down(2);
    low_pass_filter(2000, 4);
    shift_up(3);
    
    /* output the audio data to a wave file */
    FILE* fp = fopen("output.wav", "wb");
    fprintf(fp, "RIFF");
    int chunk_size = SAMPLES * CHANNELS * sizeof(short) + 36;
    fwrite(&chunk_size, 4, 1, fp);
    fprintf(fp, "WAVEfmt ");
    int subchunk1_size = 16;
    fwrite(&subchunk1_size, 4, 1, fp);
    short audio_format = 1;
    fwrite(&audio_format, 2, 1, fp);
    short num_channels = CHANNELS;
    fwrite(&num_channels, 2, 1, fp);
    int sample_rate = SAMPLE_RATE;
    fwrite(&sample_rate, 4, 1, fp);
    int byte_rate = SAMPLE_RATE * CHANNELS * sizeof(short);
    fwrite(&byte_rate, 4, 1, fp);
    short block_align = CHANNELS * sizeof(short);
    fwrite(&block_align, 2, 1, fp);
    short bits_per_sample = sizeof(short) * 8;
    fwrite(&bits_per_sample, 2, 1, fp);
    fprintf(fp, "data");
    fwrite(&chunk_size - 36, 4, 1, fp);
    for (int i = 0; i < SAMPLES; i++) {
        for (int j = 0; j < CHANNELS; j++) {
            fwrite(&audio[i][j], sizeof(short), 1, fp);
        }
    }
    fclose(fp);
    
    return 0;
}