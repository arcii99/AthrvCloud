//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

void speedtest() {
  double time_taken;
  int buffer = 50000000; // 50 MB
  char *data = (char*)calloc(buffer, sizeof(char));
  time_t start_time, end_time;
  srand(time(NULL));

  // generate random data
  for(int i = 0; i < buffer; i++) {
    data[i] = rand() % 255;
  }

  // write and read file
  FILE *fp;
  fp = fopen("test.bin", "wb");
  start_time = time(NULL);
  fwrite(data, sizeof(char), buffer, fp);
  end_time = time(NULL);
  time_taken = difftime(end_time, start_time);
  printf("Write time: %.2fs\n", time_taken);
  fclose(fp);

  fp = fopen("test.bin", "rb");
  start_time = time(NULL);
  fread(data, sizeof(char), buffer, fp);
  end_time = time(NULL);
  time_taken = difftime(end_time, start_time);
  printf("Read time: %.2fs\n", time_taken);
  fclose(fp);

  // calculate internet speed
  double bits = buffer * 8;
  double seconds = time_taken;
  double Mbps = floor((bits / seconds) / 1000000.0 * 100) / 100;

  printf("Internet Speed: %.2f Mbps\n", Mbps);
}

int main() {
  speedtest();
  return 0;
}