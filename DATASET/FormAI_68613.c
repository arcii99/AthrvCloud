//FormAI DATASET v1.0 Category: Audio processing ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

typedef struct {
    float real;
    float imag;
} complex_t;

void print_header(){
    printf("███╗   ███╗ █████╗ ███████╗███████╗██╗ ██████╗ ██╗     ██╗ ██████╗██╗  ██╗\n");
    printf("████╗ ████║██╔══██╗██╔════╝██╔════╝██║██╔═══██╗██║     ██║██╔════╝██║ ██╔╝\n");
    printf("██╔████╔██║███████║█████╗  █████╗  ██║██║   ██║██║     ██║██║     █████╔╝ \n");
    printf("██║╚██╔╝██║██╔══██║██╔══╝  ██╔══╝  ██║██║   ██║██║     ██║██║     ██╔═██╗ \n");
    printf("██║ ╚═╝ ██║██║  ██║███████╗███████╗██║╚██████╔╝███████╗██║╚██████╗██║  ██╗\n");
    printf("╚═╝     ╚═╝╚═╝  ╚═╝╚══════╝╚══════╝╚═╝ ╚═════╝ ╚══════╝╚═╝ ╚═════╝╚═╝  ╚═╝\n");
    printf("    █████╗ ██████╗ ██╗     ██╗███████╗████████╗██╗ ██████╗ ███╗   ██╗\n");
    printf("   ██╔══██╗██╔══██╗██║     ██║██╔════╝╚══██╔══╝██║██╔═══██╗████╗  ██║\n");
    printf("   ███████║██████╔╝██║     ██║███████╗   ██║   ██║██║   ██║██╔██╗ ██║\n");
    printf("   ██╔══██║██╔══██╗██║     ██║╚════██║   ██║   ██║██║   ██║██║╚██╗██║\n");
    printf("   ██║  ██║██║  ██║███████╗██║███████║   ██║   ██║╚██████╔╝██║ ╚████║\n");
    printf("   ╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚═╝╚══════╝   ╚═╝   ╚═╝ ╚═════╝ ╚═╝  ╚═══╝\n");
    printf("    ████████╗██╗  ██╗██████╗ ███████╗     ██████╗ ██████╗ ██╗   ██╗██████╗\n");
    printf("    ╚══██╔══╝██║ ██╔╝██╔══██╗██╔════╝    ██╔════╝██╔═══██╗██║   ██║██╔══██╗\n");
    printf("       ██║   █████╔╝ ██████╔╝█████╗      ██║     ██║   ██║██║   ██║██║  ██║\n");
    printf("       ██║   ██╔═██╗ ██╔══██╗██╔══╝      ██║     ██║   ██║██║   ██║██║  ██║\n");
    printf("       ██║   ██║  ██╗██████╔╝███████╗    ╚██████╗╚██████╔╝╚██████╔╝██████╔╝\n");
    printf("       ╚═╝   ╚═╝  ╚═╝╚═════╝ ╚══════╝     ╚═════╝ ╚═════╝  ╚═════╝ ╚═════╝ \n");
}

complex_t cmplx_multiply(complex_t a,complex_t b){
        complex_t ret;
        ret.real=a.real*b.real-a.imag*b.imag;
        ret.imag=a.imag*b.real+a.real*b.imag;
        return ret;
}
complex_t cmplx_add(complex_t a,complex_t b){
        complex_t ret;
        ret.real=a.real+b.real;
        ret.imag=a.imag+b.imag;
        return ret;
}
complex_t cmplx_subtract(complex_t a,complex_t b){
        complex_t ret;
        ret.real=a.real-b.real;
        ret.imag=a.imag-b.imag;
        return ret;
}

complex_t cmplx_exp(float angle){
    complex_t result;
    result.real=cosf(angle);
    result.imag=sinf(angle);
    return result;
}

void fft(complex_t x[], int n) {
    if(n<=1){
        return;
    }
    complex_t temp[n];
    for(int i=0;i<n;i++){
        if((i%2)==0){
            temp[i/2]=x[i];
        }
        else{
            temp[n/2 +i/2]=x[i];
        }
    }
    for(int i=0;i<n;i++){
        x[i]=temp[i];
    }

    fft(x,n/2);
    fft(x+n/2,n/2);
    for(int i=0;i<n/2;i++){
        complex_t temp = cmplx_multiply(x[i+n/2],cmplx_exp((-2*M_PI*i)/n));
        x[i+n/2]=cmplx_subtract(x[i],temp);
        x[i]=cmplx_add(x[i],temp);
    }
}

int main(){
        print_header();
        FILE *audio_file;
        audio_file = fopen("sample.wav", "rb");
        if (audio_file == NULL) {
                printf("Cannot open file\n");
                exit(1);
        }
        int filesize, fmtsize, audiosize, channels, samplerate, byterate, bitspersample, length;
        short audio;
        char chunk_id[4], format[4], subchunk1_id[4], subchunk2_id[4];
        fread(chunk_id, sizeof(chunk_id), 1, audio_file);
        fread(&filesize, sizeof(filesize), 1, audio_file);
        fread(format, sizeof(format), 1, audio_file);
        fread(subchunk1_id, sizeof(subchunk1_id), 1, audio_file);
        fread(&fmtsize, sizeof(fmtsize), 1, audio_file);
        fread(&audio, sizeof(audio), 1, audio_file);
        fread(&channels, sizeof(channels), 1, audio_file);
        fread(&samplerate, sizeof(samplerate), 1, audio_file);
        fread(&byterate, sizeof(byterate), 1, audio_file);
        fread(&audio, sizeof(audio), 1, audio_file);
        fread(&bitspersample, sizeof(bitspersample), 1, audio_file);
        fread(subchunk2_id, sizeof(subchunk2_id), 1, audio_file);
        fread(&audiosize, sizeof(audiosize), 1, audio_file);

        if(fmtsize == 18) {
            int32_t dummysize;
            fread(&dummysize, sizeof(dummysize), 1, audio_file);
            fseek(audio_file, dummysize-18, SEEK_CUR);
        } else {
            fseek(audio_file, fmtsize-16, SEEK_CUR);
        }

        length = audiosize / ((bitspersample / 8) * channels);
        printf("File size: %d bytes\n", filesize);
        printf("Audio format: %d\n", audio);
        printf("Channels: %d\n", channels);
        printf("Sample rate: %d Hz\n", samplerate);
        printf("Byte rate: %d bytes/s\n", byterate);
        printf("Bits per sample: %d\n", bitspersample);
        printf("Length: %d samples\n", length);

        short buffer[audiosize];
        fread(buffer, audiosize, 1, audio_file);
        fclose(audio_file);
        float X[length];

        for (int i = 0; i < length; i++) {
            X[i] = buffer[i] / 32768.0;
        }
        complex_t complexX[length];
        for(int i=0;i<length;i++){
            complexX[i].real=X[i];
            complexX[i].imag=0.0;
        }

        fft(complexX,length);

        printf("Frequency analysis:\n");
        for (int i = 0; i < length / 2;i++){
            float freq = i * (float)samplerate / length;
            float amplitude = sqrt(complexX[i].real * complexX[i].real + complexX[i].imag * complexX[i].imag)/length;
            printf("%f %f\n", freq, amplitude);
        }

        return 0;
}