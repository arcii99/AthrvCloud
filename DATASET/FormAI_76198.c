//FormAI DATASET v1.0 Category: Digital signal processing ; Style: shape shifting
//This program demonstrates the use of digital signal processing to shape shift audio 
//The program takes an input audio file and applies various filters and effects to shape-shift the audio
//The shape-shifting is done by changing the frequency response of the audio signal

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

#define BUFFER_SIZE 2048 //buffer size for reading audio data
#define PI 3.14159265358979323846

typedef struct {
    int16_t left_channel;
    int16_t right_channel;
} stereo_sample; //structure to store stereo audio samples

//function to read audio data from a WAV file
int read_audio_data(FILE* audio_file, stereo_sample* samples, int num_samples) {
    char header[44];
    if (fread(header, sizeof(char), 44, audio_file) != 44) {
        return 0;
    }
    int num_bytes = num_samples * sizeof(stereo_sample);
    return fread(samples, sizeof(stereo_sample), num_samples, audio_file) == num_samples;
}

//function to write audio data to a WAV file
void write_audio_data(FILE* audio_file, stereo_sample* samples, int num_samples) {
    char header[44];
    int num_bytes = num_samples * sizeof(stereo_sample);
    header[0] = 'R';
    header[1] = 'I';
    header[2] = 'F';
    header[3] = 'F';
    *((int32_t*)(header + 4)) = num_bytes + 36;
    header[8] = 'W';
    header[9] = 'A';
    header[10] = 'V';
    header[11] = 'E';
    header[12] = 'f';
    header[13] = 'm';
    header[14] = 't';
    header[15] = ' ';
    *((int32_t*)(header + 16)) = 16;
    *((int16_t*)(header + 20)) = 1;
    *((int16_t*)(header + 22)) = 2;
    *((int32_t*)(header + 24)) = 44100;
    *((int32_t*)(header + 28)) = 88200;
    *((int16_t*)(header + 32)) = 4;
    *((int16_t*)(header + 34)) = 16;
    header[36] = 'd';
    header[37] = 'a';
    header[38] = 't';
    header[39] = 'a';
    *((int32_t*)(header + 40)) = num_bytes;
    fwrite(header, sizeof(char), 44, audio_file);
    fwrite(samples, sizeof(stereo_sample), num_samples, audio_file);
}

//function to apply a low-pass filter to the audio
void low_pass_filter(double* input, double* output, int num_samples, double cutoff_freq, double sample_rate) {
    double omega_c = 2 * PI * cutoff_freq / sample_rate;
    double alpha = sin(omega_c) / (2 * 0.707);
    double a0 = 1 + alpha;
    double a1 = -2 * cos(omega_c);
    double a2 = 1 - alpha;
    double b0 = (1 - cos(omega_c)) / 2;
    double b1 = 1 - cos(omega_c);
    double b2 = (1 - cos(omega_c)) / 2;
    double x0, x1, x2, y0, y1, y2;
    x1 = x2 = y1 = y2 = 0;
    for (int i = 0; i < num_samples; i++) {
        x0 = input[i];
        y0 = (b0 / a0)*x0 + (b1 / a0)*x1 + (b2 / a0)*x2 - (a1 / a0)*y1 - (a2 / a0)*y2;
        x2 = x1;
        x1 = x0;
        y2 = y1;
        y1 = y0;
        output[i] = y0;
    }
}

//function to apply a high-pass filter to the audio
void high_pass_filter(double* input, double* output, int num_samples, double cutoff_freq, double sample_rate) {
    double omega_c = 2 * PI * cutoff_freq / sample_rate;
    double alpha = sin(omega_c) / (2 * 0.707);
    double a0 = 1 + alpha;
    double a1 = -2 * cos(omega_c);
    double a2 = 1 - alpha;
    double b0 = (1 + cos(omega_c)) / 2;
    double b1 = -(1 + cos(omega_c));
    double b2 = (1 + cos(omega_c)) / 2;
    double x0, x1, x2, y0, y1, y2;
    x1 = x2 = y1 = y2 = 0;
    for (int i = 0; i < num_samples; i++) {
        x0 = input[i];
        y0 = (b0 / a0)*x0 + (b1 / a0)*x1 + (b2 / a0)*x2 - (a1 / a0)*y1 - (a2 / a0)*y2;
        x2 = x1;
        x1 = x0;
        y2 = y1;
        y1 = y0;
        output[i] = y0;
    }
}

//function to apply a band-pass filter to the audio
void band_pass_filter(double* input, double* output, int num_samples, double cutoff_freq_low, double cutoff_freq_high, double sample_rate) {
    double omega_c1 = 2 * PI * cutoff_freq_low / sample_rate;
    double omega_c2 = 2 * PI * cutoff_freq_high / sample_rate;
    double alpha = sin((omega_c2 - omega_c1) / 2) / cos((omega_c2 - omega_c1) / 2);
    double a0 = 1 + alpha;
    double a1 = -2 * cos((omega_c2 + omega_c1) / 2);
    double a2 = 1 - alpha;
    double b0 = alpha;
    double b1 = 0;
    double b2 = -alpha;
    double x0, x1, x2, y0, y1, y2;
    x1 = x2 = y1 = y2 = 0;
    for (int i = 0; i < num_samples; i++) {
        x0 = input[i];
        y0 = (b0 / a0)*x0 + (b1 / a0)*x1 + (b2 / a0)*x2 - (a1 / a0)*y1 - (a2 / a0)*y2;
        x2 = x1;
        x1 = x0;
        y2 = y1;
        y1 = y0;
        output[i] = y0;
    }
}

//function to apply a flanger effect to the audio
void flanger(double* input, double* output, int num_samples, double delay_time, double modulation_depth, double sample_rate) {
    double max_delay_samples = (delay_time * sample_rate > num_samples) ? num_samples : delay_time * sample_rate;
    double modulation_freq = 2 * PI * sample_rate / max_delay_samples;
    double depth_samples = modulation_depth / 100 * max_delay_samples;
    double x0, y0;
    for (int i = 0; i < num_samples; i++) {
        if (i < max_delay_samples) {
            x0 = input[i] + input[(int)(i + depth_samples*sin(modulation_freq*i)) % (int)max_delay_samples];
            y0 = x0 / 2;
        }
        else {
            x0 = input[i] + input[(int)(i + depth_samples*sin(modulation_freq*i)) % (int)max_delay_samples];
            y0 = x0 / 2 + output[i - (int)max_delay_samples] / 2;
        }
        output[i] = y0;
    }
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Usage: %s [input filename] [output filename]\n", argv[0]);
        return -1;
    }
    FILE* input_file = fopen(argv[1], "rb");
    if (!input_file) {
        printf("Error: Could not open input file '%s'\n", argv[1]);
        return -1;
    }
    FILE* output_file = fopen(argv[2], "wb");
    if (!output_file) {
        printf("Error: Could not open output file '%s'\n", argv[2]);
        fclose(input_file);
        return -1;
    }
    stereo_sample buffer[BUFFER_SIZE];
    double input_samples[BUFFER_SIZE];
    double output_samples[BUFFER_SIZE];
    int num_samples_read = 0;
    double sample_rate = 44100;
    while ((num_samples_read = read_audio_data(input_file, buffer, BUFFER_SIZE)) > 0) {
        for (int i = 0; i < num_samples_read; i++) {
            input_samples[i] = ((double)buffer[i].left_channel + (double)buffer[i].right_channel) / 2;
        }
        //apply low-pass filter
        low_pass_filter(input_samples, output_samples, num_samples_read, 1000, sample_rate);
        //apply high-pass filter
        high_pass_filter(output_samples, input_samples, num_samples_read, 5000, sample_rate);
        //apply band-pass filter
        band_pass_filter(input_samples, output_samples, num_samples_read, 1000, 5000, sample_rate);
        //apply flanger effect
        flanger(output_samples, input_samples, num_samples_read, 0.008, 50, sample_rate);
        for (int i = 0; i < num_samples_read; i++) {
            buffer[i].left_channel = buffer[i].right_channel = (int16_t)round(input_samples[i]);
        }
        write_audio_data(output_file, buffer, num_samples_read);
    }
    fclose(input_file);
    fclose(output_file);
    return 0;
}