//FormAI DATASET v1.0 Category: Audio processing ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define BUFF_SIZE 2048

typedef struct _wave_t {
    char chunk_id[4];
    int chunk_size;
    char format[4];
    char subchunk1_id[4];
    int subchunk1_size;
    short audio_format;
    short num_channels;
    int sample_rate;
    int byte_rate;
    short block_align;
    short bits_per_sample;
    char subchunk2_id[4];
    int subchunk2_size;
    short *data;
} wave_t;

void read_data(FILE *fp, wave_t *wave) {
    int i, j, sample;

    for (i = 0; i < wave->subchunk2_size / sizeof(wave->data[0]); i++) {
        for (sample = 0; sample < wave->num_channels; sample++) {
            wave->data[i * wave->num_channels + sample] = 0;

            for (j = 0; j < wave->bits_per_sample / 8; j++) {
                wave->data[i * wave->num_channels + sample] +=
                    (short)fgetc(fp) << (j * 8);
            }
        }
    }
}

void write_data(FILE *fp, wave_t *wave) {
    int i, j, sample;

    for (i = 0; i < wave->subchunk2_size / sizeof(wave->data[0]); i++) {
        for (sample = 0; sample < wave->num_channels; sample++) {
            for (j = 0; j < wave->bits_per_sample / 8; j++) {
                fputc(wave->data[i * wave->num_channels + sample] >> (j * 8) & 0xff, fp);
            }
        }
    }
}

void trim_silence(wave_t *wave) {
    int i, j;
    short *data = wave->data;
    int num_samples = wave->subchunk2_size / sizeof(data[0]) / wave->num_channels;
    int first_non_silent = -1;
    int last_non_silent;

    for (i = 0; i < num_samples; i++) {
        for (j = 0; j < wave->num_channels; j++) {
            if (data[i * wave->num_channels + j] != 0) {
                first_non_silent = i;
                goto outer;
            }
        }
    }

outer:
    if (first_non_silent == -1) {
        first_non_silent = 0;
        last_non_silent = num_samples - 1;
        goto done;
    }

    for (i = num_samples - 1; i >= 0; i--) {
        for (j = 0; j < wave->num_channels; j++) {
            if (data[i * wave->num_channels + j] != 0) {
                last_non_silent = i;
                goto outer2;
            }
        }
    }

outer2:
    {
        int num_trimmed_samples = (num_samples - last_non_silent) +
            (first_non_silent - 0);
        short *new_data = calloc(num_trimmed_samples * wave->num_channels,
                                 sizeof(wave->data[0]));
        memcpy(&new_data[(first_non_silent - 0) * wave->num_channels],
               &data[first_non_silent * wave->num_channels],
               (last_non_silent - first_non_silent + 1) *
               wave->num_channels * sizeof(wave->data[0]));
        free(wave->data);
        wave->data = new_data;
        wave->subchunk2_size = num_trimmed_samples * wave->num_channels *
            sizeof(wave->data[0]);
    }

done:
    return;
}

void apply_filter(wave_t *wave, double (*filter)(double, double)) {
    double *data = calloc(wave->subchunk2_size / sizeof(wave->data[0]),
                          sizeof(data[0]));
    double factor = pow(2, wave->bits_per_sample - 1);
    double inverse_factor = 1.0 / factor;
    int num_samples = wave->subchunk2_size / sizeof(wave->data[0]);

    for (int i = 0; i < num_samples; i++) {
        for (int j = 0; j < wave->num_channels; j++) {
            data[i * wave->num_channels + j] =
                filter(data[i * wave->num_channels + j] * inverse_factor, i *
                       1.0 / wave->sample_rate) * factor;
        }
    }

    for (int i = 0; i < num_samples; i++) {
        for (int j = 0; j < wave->num_channels; j++) {
            double val = data[i * wave->num_channels + j];

            if (val > factor - 1) {
                wave->data[i * wave->num_channels + j] = factor - 1;
            } else if (val < -factor) {
                wave->data[i * wave->num_channels + j] = -factor;
            } else {
                wave->data[i * wave->num_channels + j] = (short)val;
            }
        }
    }

    free(data);
}

void lowpass_filter(wave_t *wave, double cutoff) {
    double RC, DT, alpha, y_prev, cutoff_normalized, x_prev;
    RC = 1.0 / (2.0 * M_PI * cutoff);
    DT = 1.0 / wave->sample_rate;
    alpha = DT / (RC + DT);
    y_prev = 0.0;

    cutoff_normalized = cutoff / (wave->sample_rate / 2.0);

    double filter(double x, double t) {
        double y = alpha * x + (1 - alpha) * y_prev;
        y_prev = y;
        return y;
    }

    apply_filter(wave, filter);
}

void highpass_filter(wave_t *wave, double cutoff) {
    double RC, DT, alpha, y_prev, cutoff_normalized, x_prev;
    RC = 1.0 / (2.0 * M_PI * cutoff);
    DT = 1.0 / wave->sample_rate;
    alpha = RC / (RC + DT);
    y_prev = 0.0;

    cutoff_normalized = cutoff / (wave->sample_rate / 2.0);

    double filter(double x, double t) {
        double y = alpha * y_prev + alpha * (x - x_prev);
        x_prev = x;
        y_prev = y;
        return y;
    }

    apply_filter(wave, filter);
}

void echo_filter(wave_t *wave, double delay, double multiplier) {
    int delay_samples = delay * wave->sample_rate;
    double *data = calloc(wave->subchunk2_size / sizeof(wave->data[0]),
                          sizeof(data[0]));
    double factor = pow(2, wave->bits_per_sample - 1);
    int num_samples = wave->subchunk2_size / sizeof(wave->data[0]);

    memcpy(data, wave->data, wave->subchunk2_size);

    for (int i = delay_samples; i < num_samples; i++) {
        for (int j = 0; j < wave->num_channels; j++) {
            double a = data[(i - delay_samples) * wave->num_channels + j];
            double b = data[i * wave->num_channels + j] * multiplier;
            wave->data[i * wave->num_channels + j] = fmin(+1.0, fmax(-1.0,
                                      a + b));
        }
    }

    free(data);
}

int main(int argc, char **argv) {
    if (argc < 4) {
        printf("usage: %s <input.wav> <output.wav> <lowpass/highpass/echo> [args]\n",
               argv[0]);
        exit(1);
    }

    char *input_filename = argv[1];
    char *output_filename = argv[2];
    char *filter_name = argv[3];

    FILE *fp = fopen(input_filename, "rb");
    wave_t wave;

    if (fp == NULL) {
        printf("error: couldn't open %s\n", input_filename);
        exit(1);
    }

    fread(&wave, sizeof(wave), 1, fp);

    if (memcmp(wave.chunk_id, "RIFF", 4) != 0 ||
            memcmp(wave.format, "WAVE", 4) != 0 ||
            memcmp(wave.subchunk1_id, "fmt ", 4) != 0 ||
            wave.subchunk1_size != 16) {
        printf("error: %s is not a valid (uncompressed) WAV file\n",
               input_filename);
        exit(1);
    }

    if (strcmp(filter_name, "lowpass") == 0 ||
            strcmp(filter_name, "highpass") == 0) {
        if (argc != 5) {
            printf("error: %s needs a frequency argument\n", filter_name);
            exit(1);
        }

        double cutoff = atof(argv[4]);

        if (strcmp(filter_name, "lowpass") == 0) {
            lowpass_filter(&wave, cutoff);
        } else {
            highpass_filter(&wave, cutoff);
        }
    } else if (strcmp(filter_name, "echo") == 0) {
        if (argc != 5) {
            printf("error: echo needs a delay argument\n");
            exit(1);
        }

        double delay = atof(argv[4]);

        if (argc == 6) {
            double multiplier = atof(argv[5]);
            echo_filter(&wave, delay, multiplier);
        } else {
            echo_filter(&wave, delay, 0.8);
        }
    } else {
        printf("error: unknown filter %s\n", filter_name);
        exit(1);
    }

    trim_silence(&wave);

    FILE *outfp = fopen(output_filename, "wb");

    if (outfp == NULL) {
        printf("error: couldn't open %s for writing\n", output_filename);
        exit(1);
    }

    int data_size = sizeof(short) * wave.subchunk2_size / sizeof(wave.data[0]);

    fwrite(&wave, sizeof(wave), 1, outfp);
    fwrite(&data_size, sizeof(data_size), 1, outfp);
    write_data(outfp, &wave);
    fclose(fp);
    fclose(outfp);
    return 0;
}