//FormAI DATASET v1.0 Category: Audio processing ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

/* function to load PCM data from an input file */
short* loadPCMData(char* filename, int* numFrames, int* numChannels, int* sampleRate) {
    FILE* fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: Unable to open '%s' for reading\n", filename);
        exit(1);
    }
    
    // read and parse the PCM header
    char header[44];
    fread(header, sizeof(char), 44, fp);
    
    *numChannels = header[22] | (header[23] << 8);
    *sampleRate = header[24] | (header[25] << 8) | (header[26] << 16) | (header[27] << 24);
    int byteRate = header[28] | (header[29] << 8) | (header[30] << 16) | (header[31] << 24);
    int bitsPerSample = header[34] | (header[35] << 8);
    int dataSize = header[40] | (header[41] << 8) | (header[42] << 16) | (header[43] << 24);
    
    *numFrames = dataSize / (*numChannels * (bitsPerSample/8));
    
    // allocate memory for PCM data
    short* pcmData = (short*)malloc(dataSize);
    
    // read in the PCM data
    fread(pcmData, sizeof(short), *numFrames * *numChannels, fp);
    
    fclose(fp);
    return pcmData;
}

/* function to write PCM data to an output file */
void writePCMData(char* filename, short* pcmData, int numFrames, int numChannels, int sampleRate) {
    FILE* fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Error: Unable to open '%s' for writing\n", filename);
        exit(1);
    }
    
    // write the PCM header
    char header[44];
    header[0] = 'R'; header[1] = 'I'; header[2] = 'F'; header[3] = 'F';
    int dataSize = numFrames * numChannels * sizeof(short);
    header[4] = dataSize & 0xff; header[5] = (dataSize >> 8) & 0xff; header[6] = (dataSize >> 16) & 0xff; header[7] = (dataSize >> 24) & 0xff;
    header[8] = 'W'; header[9] = 'A'; header[10] = 'V'; header[11] = 'E';
    header[12] = 'f'; header[13] = 'm'; header[14] = 't'; header[15] = ' ';
    header[16] = 0x10; header[17] = 0; header[18] = 0; header[19] = 0;
    header[20] = 1; header[21] = 0;
    header[22] = numChannels & 0xff; header[23] = (numChannels >> 8) & 0xff;
    header[24] = sampleRate & 0xff; header[25] = (sampleRate >> 8) & 0xff; header[26] = (sampleRate >> 16) & 0xff; header[27] = (sampleRate >> 24) & 0xff;
    int byteRate = sampleRate * numChannels * sizeof(short);
    header[28] = byteRate & 0xff; header[29] = (byteRate >> 8) & 0xff; header[30] = (byteRate >> 16) & 0xff; header[31] = (byteRate >> 24) & 0xff;
    header[32] = numChannels * sizeof(short);
    header[33] = 0;
    header[34] = 16; header[35] = 0;
    header[36] = 'd'; header[37] = 'a'; header[38] = 't'; header[39] = 'a';
    dataSize = numFrames * numChannels * sizeof(short);
    header[40] = dataSize & 0xff; header[41] = (dataSize >> 8) & 0xff; header[42] = (dataSize >> 16) & 0xff; header[43] = (dataSize >> 24) & 0xff;
    fwrite(header, sizeof(char), 44, fp);
    
    // write the PCM data
    fwrite(pcmData, sizeof(short), numFrames * numChannels, fp);
    
    fclose(fp);
}

/* function to apply an envelope to a buffer of PCM data */
void applyEnvelope(short* pcmData, int numFrames, int numChannels, int sampleRate, float attackTime, float decayTime, float sustainLevel, float releaseTime) {
    float attackCoeff = expf(-1/(sampleRate*attackTime));
    float decayCoeff = expf(-1/(sampleRate*decayTime));
    float releaseCoeff = expf(-1/(sampleRate*releaseTime));
    
    float currentLevel = 0;
    float targetLevel = 0;
    float sustainCoeff = 0;
    
    for (int channel = 0; channel < numChannels; channel++) {
        currentLevel = 0;
        targetLevel = 0;
        sustainCoeff = sustainLevel/32767.0;

        for (int i = 0; i < numFrames; i++) {
            if (pcmData[numChannels*i + channel] > currentLevel) {
                currentLevel = attackCoeff * currentLevel + (1-attackCoeff) * pcmData[numChannels*i + channel];
            }
            else {
                currentLevel = decayCoeff * currentLevel + (1-decayCoeff) * pcmData[numChannels*i + channel];
            }
            
            if (i > numFrames/2 && currentLevel < sustainLevel) {
                sustainCoeff = currentLevel/32767.0;
            }
            
            targetLevel = sustainCoeff * 32767.0;
            
            if (pcmData[numChannels*i + channel] < targetLevel) {
                pcmData[numChannels*i + channel] = (short)(releaseCoeff * pcmData[numChannels*i + channel] + (1-releaseCoeff) * targetLevel);
            }
        }
    }
}

int main(int argc, char** argv) {
    if (argc != 7) {
        printf("Usage: %s input.wav output.wav attackTime decayTime sustainLevel releaseTime\n", argv[0]);
        exit(1);
    }
    
    char* inputFilename = argv[1];
    char* outputFilename = argv[2];
    float attackTime = atof(argv[3]);
    float decayTime = atof(argv[4]);
    float sustainLevel = atof(argv[5]);
    float releaseTime = atof(argv[6]);
    
    int numFrames;
    int numChannels;
    int sampleRate;
    
    short* pcmData = loadPCMData(inputFilename, &numFrames, &numChannels, &sampleRate);
    
    applyEnvelope(pcmData, numFrames, numChannels, sampleRate, attackTime, decayTime, sustainLevel, releaseTime);
    
    writePCMData(outputFilename, pcmData, numFrames, numChannels, sampleRate);
    
    free(pcmData);
    
    return 0;
}