//FormAI DATASET v1.0 Category: Audio processing ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

void delay(int delayTime) {
  for(int i=0; i<delayTime*1000000; i++);
}

int main() {
  FILE *audioFile;
  char fileHeader[44];
  int audioLength, sampleRate, numChannels, sampleSize;
  short sampleData;
  
  audioFile = fopen("medieval_audio.wav", "rb");
  if(audioFile == NULL) {
    printf("Error: File not found");
    return 0;
  }
  
  fread(fileHeader, 1, 44, audioFile);
  audioLength = *(int*)(fileHeader+40);
  sampleRate = *(int*)(fileHeader+24);
  numChannels = *(short*)(fileHeader+22);
  sampleSize = *(short*)(fileHeader+34)/8;
  
  printf("Audio length: %dms\nSample rate: %dHz\nNum channels: %d\nSample size: %d-bit\n", audioLength, sampleRate, numChannels, sampleSize*8);
  
  while(1) {
    fread(&sampleData, sampleSize, 1, audioFile);
    
    if(sampleData > 1000) {
      printf("[SOUND EFFECT]\n");
      delay(100);
    }
    
    if(ftell(audioFile) >= audioLength+44)  // If end of file is reached
      break;
  }
  
  fclose(audioFile);
  
  return 0;
}