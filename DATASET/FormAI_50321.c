//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: futuristic
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<math.h>

int main()
{

  //initialize variables
  int rssi;
  int frequency;
  int noise;
  int quality;
  int signal;
  int channel;
  int i;

  printf("Enter details:");
  scanf("%d%d%d", &rssi, &frequency, &noise);

  //calculate signal strength and quality
  signal = (int) round(2*(rssi - 0.5*(131 + 10*log10(frequency))) - noise);
  quality = signal*100/60;

  //determine channel
  channel = floor((frequency - 2407)/5);

  //print results
  printf("Signal Strength: %d dBm\n", signal);
  printf("Signal Quality: %d %%\n", quality);
  printf("Channel: %d\n", channel);

  //analyze signal quality
  if(quality < 50) {
    printf("Poor signal quality. Please move closer to the router.");
  } else {
    printf("Good signal quality. Enjoy your Wi-Fi!");
  }

  return 0;
}