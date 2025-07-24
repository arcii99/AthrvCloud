//FormAI DATASET v1.0 Category: Audio processing ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846
#define SAMPLE_RATE 44100

double oscillator(double frequency, double time)
{
    return sin(2.0 * PI * frequency * time);
}

double square_wave(double frequency, double time)
{
    return (oscillator(frequency, time) > 0) ? 1.0 : -1.0;
}

double sawtooth_wave(double frequency, double time)
{
    double period = 1.0 / frequency;
    double phase = fmod(time, period) / period;
    return (phase * 2.0) - 1.0;
}

double triangle_wave(double frequency, double time)
{
    double period = 1.0 / frequency;
    double phase = fmod(time, period) / period;
    double value = (phase < 0.5) ? phase * 4.0 : (1.0 - phase) * 4.0;
    return (value - 1.0);
}

double lowpass_filter(double input, double output, double cutoff, double resonance)
{
    double omega = 2.0 * PI * cutoff / SAMPLE_RATE;
    double alpha = sin(omega) / (2.0 * resonance);
    double feedback = output * (1.0 - alpha) + input * alpha;
    return feedback;
}

double highpass_filter(double input, double output, double cutoff, double resonance)
{
    double omega = 2.0 * PI * cutoff / SAMPLE_RATE;
    double alpha = sin(omega) / (2.0 * resonance);
    double feedback = output * (1.0 - alpha) + input * alpha;
    return input - feedback;
}

int main(int argc, char* argv[])
{
    FILE* file = fopen("audio.raw","wb");
    if (file == NULL) {
        printf("Failed to open file\n");
        return 1;
    }

    double frequency = 440.0;
    double time = 0.0;
    double duration = 5.0;
    double amplitude = 0.5;
    double cutoff = 2000.0;
    double resonance = 1.0;

    int samples = duration * SAMPLE_RATE;
    for (int i = 0; i < samples; i++) {
        time += 1.0 / SAMPLE_RATE;

        double signal = triangle_wave(frequency, time);
        double filtered_signal = lowpass_filter(signal * amplitude, filtered_signal, cutoff, resonance);

        fwrite(&filtered_signal, sizeof(double), 1, file);
    }

    fclose(file);
    return 0;
}