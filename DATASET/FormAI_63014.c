//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  printf("Welcome to the Internet Speed Test\n");

  // Variables to hold the test results
  float download_speed, upload_speed, latency;

  // Random number generation to simulate test results
  srand(time(NULL));
  download_speed = (float) (rand() % 50 + 1); // Random values between 1 and 50
  upload_speed = (float) (rand() % 50 + 1);
  latency = (float) (rand() % 1000 + 1); // Latency between 1ms and 1000ms

  // Display the test results
  printf("Download Speed: %.2f Mbps\n", download_speed);
  printf("Upload Speed: %.2f Mbps\n", upload_speed);
  printf("Latency: %.2f ms\n", latency);

  // Calculate the mean and standard deviation of the download speeds
  float speeds[] = {17.75, 24.38, 5.53, 32.46, 7.91, 11.71, 22.18, 28.97, 19.05, 38.06};
  int num_speeds = sizeof(speeds)/sizeof(speeds[0]);

  // Calculate the mean
  float mean = 0;
  for (int i=0; i<num_speeds; i++) {
    mean += speeds[i];
  }
  mean /= num_speeds;

  // Calculate the standard deviation
  float sd = 0;
  for (int i=0; i<num_speeds; i++) {
    sd += pow(speeds[i] - mean, 2);
  }
  sd = sqrt(sd/num_speeds);

  // Display the mean and standard deviation
  printf("Mean download speed: %.2f Mbps\n", mean);
  printf("Standard deviation of download speeds: %.2f Mbps\n", sd);

  return 0;
}