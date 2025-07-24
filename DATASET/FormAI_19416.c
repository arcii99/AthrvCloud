//FormAI DATASET v1.0 Category: Audio processing ; Style: Romeo and Juliet
/* A Romeo and Juliet audio processing program */

#include <stdio.h>
#include <stdlib.h>

int main() {
  // Initialize audio file
  FILE *audio;
  audio = fopen("love_song.wav", "rb");

  // Check if file exists
  if (!audio) {
      printf("Alas, our love song does not exist! \n");
      return 0;
  }

  // Read audio file
  int audio_data[5000];
  fread(audio_data, sizeof(int), 5000, audio);
  
  // Romeo's processing
  for (int i = 0; i < 5000; i++) {
    audio_data[i] = audio_data[i] * 2;
  }
  
  // Juliet's processing
  for (int i = 0; i < 5000; i++) {
    audio_data[i] = audio_data[i] / 2;
  }

  // Write processed audio data to new file
  FILE *new_audio;
  new_audio = fopen("love_song_processed.wav", "wb");
  fwrite(audio_data, sizeof(int), 5000, new_audio);

  // Close files
  fclose(audio);
  fclose(new_audio);

  printf("Oh how sweet our love song sounds, forevermore! \n");
  return 0;
}