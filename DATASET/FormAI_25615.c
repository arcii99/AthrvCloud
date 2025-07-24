//FormAI DATASET v1.0 Category: Audio processing ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846
#define FRAME_SIZE 512

void hammingWindow(float* samples, int length);
void shiftBuffer(float* buffer, int length, int shiftAmount);
void processFrame(float* inputBuffer, float* outputBuffer, int length, float* previousPhase, float* magnitudeSpectrum);

int main(int argc, char* argv[]) {
    FILE* inputFile;
    FILE* outputFile;
    float inputBuffer[FRAME_SIZE];
    float outputBuffer[FRAME_SIZE];
    float previousPhase[FRAME_SIZE / 2 + 1];
    float magnitudeSpectrum[FRAME_SIZE / 2 + 1];
    int bytesRead;

    if (argc < 3) {
        printf("Usage: program input.wav output.wav\n");
        return -1;
    }

    inputFile = fopen(argv[1], "rb");
    outputFile = fopen(argv[2], "wb");

    if (!inputFile || !outputFile) {
        printf("Error opening file(s)\n");
        return -1;
    }

    while (1) {
        bytesRead = fread(inputBuffer, sizeof(float), FRAME_SIZE, inputFile);

        if (bytesRead < FRAME_SIZE) {
            break;
        }

        hammingWindow(inputBuffer, FRAME_SIZE);

        processFrame(inputBuffer, outputBuffer, FRAME_SIZE, previousPhase, magnitudeSpectrum);

        fwrite(outputBuffer, sizeof(float), FRAME_SIZE, outputFile);

        shiftBuffer(inputBuffer, FRAME_SIZE, FRAME_SIZE / 2);
        shiftBuffer(previousPhase, FRAME_SIZE / 2 + 1, FRAME_SIZE / 2);
        shiftBuffer(magnitudeSpectrum, FRAME_SIZE / 2 + 1, FRAME_SIZE / 2);
    }

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}

void hammingWindow(float* samples, int length) {
    int i;

    for (i = 0; i < length; i++) {
        samples[i] *= 0.54 - 0.46 * cos(2 * PI * i / (length - 1));
    }
}

void shiftBuffer(float* buffer, int length, int shiftAmount) {
    int i;

    for (i = 0; i < length - shiftAmount; i++) {
        buffer[i] = buffer[i + shiftAmount];
    }
}

void processFrame(float* inputBuffer, float* outputBuffer, int length, float* previousPhase, float* magnitudeSpectrum) {
    int i, j;
    float realSpectrum[length];
    float imaginarySpectrum[length];
    float newPhase[length / 2 + 1];
    float phaseDifference;
    float phase;
    float frequency;

    for (i = 0; i < length; i++) {
        realSpectrum[i] = inputBuffer[i];

        // Zero out the imaginary part
        imaginarySpectrum[i] = 0;
    }

    // Apply the FFT to the real and imaginary parts
    FFT(realSpectrum, imaginarySpectrum, length, 1);

    // Compute the magnitude spectrum and phase spectrum
    for (i = 0; i <= length / 2; i++) {
        magnitudeSpectrum[i] = sqrt(realSpectrum[i] * realSpectrum[i] + imaginarySpectrum[i] * imaginarySpectrum[i]);

        // Compute the phase spectrum
        if (realSpectrum[i] == 0) {
            phase = PI / 2;

            if (imaginarySpectrum[i] < 0) {
                phase *= -1;
            }
        } else {
            phase = atan(imaginarySpectrum[i] / realSpectrum[i]);

            if (realSpectrum[i] < 0) {
                phase += PI;
            }
        }

        newPhase[i] = phase;

        // Compute the phase difference between this frame and the previous frame
        phaseDifference = newPhase[i] - previousPhase[i];

        // Correct the phase difference to be between -pi and pi
        while (phaseDifference > PI) {
            phaseDifference -= 2 * PI;
        }

        while (phaseDifference < -PI) {
            phaseDifference += 2 * PI;
        }

        // Compute the new phase
        phase = previousPhase[i] + 0.5 * phaseDifference;

        // Wrap the phase to be between -pi and pi
        while (phase >= PI) {
            phase -= 2 * PI;
        }

        while (phase < -PI) {
            phase += 2 * PI;
        }

        // Store the previous phase for the next frame
        previousPhase[i] = newPhase[i];

        // Compute the frequency for this component
        frequency = i * 44100.0 / length;

        // Zero out frequencies outside of the band
        if (frequency < 1200 || frequency > 1600) {
            magnitudeSpectrum[i] = 0;
        }

        // Reconstruct the complex spectrum from the magnitude and phase spectra
        realSpectrum[i] = magnitudeSpectrum[i] * cos(phase);
        imaginarySpectrum[i] = magnitudeSpectrum[i] * sin(phase);
    }

    // Apply the inverse FFT to the reconstructed spectrum
    FFT(realSpectrum, imaginarySpectrum, length, -1);

    // Copy the real part of the result to the output buffer
    for (i = 0; i < length; i++) {
        outputBuffer[i] = realSpectrum[i] / length;
    }
}

void FFT(float* real, float* imag, int n, int inverse) {
    int i, j, k;
    int m;
    float tempr, tempi;
    float wr, wi;
    float theta;

    j = 0;

    for (i = 0; i < n - 1; i++) {
        if (i < j) {
            tempr = real[j];
            tempi = imag[j];
            real[j] = real[i];
            imag[j] = imag[i];
            real[i] = tempr;
            imag[i] = tempi;
        }

        k = n / 2;

        while (k <= j) { 
            j -= k; 
            k /= 2; 
        }

        j += k;
    }

    m = 2;

    while (n > m) {
        theta = 2 * PI / m;

        if (inverse == 1) {
            theta *= -1;
        }

        wr = 1;
        wi = 0;

        for (i = 0; i < m / 2; i++) {
            for (j = i; j < n; j += m) {
                k = j + m / 2;
                tempr = wr * real[k] - wi * imag[k];
                tempi = wr * imag[k] + wi * real[k];
                real[k] = real[j] - tempr;
                imag[k] = imag[j] - tempi;
                real[j] += tempr;
                imag[j] += tempi;
            }

            wr = cos(theta) * wr - sin(theta) * wi;
            wi = sin(theta) * wr + cos(theta) * wi;
        }

        m *= 2;
    }
}