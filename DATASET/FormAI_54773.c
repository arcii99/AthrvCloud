//FormAI DATASET v1.0 Category: Audio processing ; Style: beginner-friendly
#include<stdio.h>
#include<math.h>

#define BUFFERSIZE 1024

int main() {
    FILE *fpin, *fpout;
    int bufferSize = BUFFERSIZE;
    short buffer[BUFFERSIZE];
    double theta = M_PI / 3.0;
    int i, samplesRead, shortVolume;
    double doubleVolume;

    fpin = fopen("input.raw", "rb");
    fpout = fopen("output.raw", "wb");

    while (1) {
        samplesRead = fread(buffer, sizeof(short), bufferSize, fpin);
        if (samplesRead <= 0) break;
        for (i = 0; i < samplesRead; i++) {
            shortVolume = buffer[i];
            doubleVolume = (double)shortVolume / 32767.0;
            doubleVolume *= sin(theta*i);
            buffer[i] = (short)(doubleVolume * 32767.0);
        }
        fwrite(buffer, sizeof(short), samplesRead, fpout);
    }

    fclose(fpin);
    fclose(fpout);

    return 0;
}