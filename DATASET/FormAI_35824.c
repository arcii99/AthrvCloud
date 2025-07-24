//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WAIT_TIME 3

void print_header() {
  printf("|------------------------------------------------|\n");
  printf("|                  Network QoS Monitor           |\n");
  printf("|------------------------------------------------|\n");
}

void print_timestamp() {
  time_t rawtime;
  struct tm * timeinfo;

  time(&rawtime);
  timeinfo = localtime(&rawtime);
  printf("Timestamp: %s", asctime(timeinfo));
}

int main() {
  int network_quality;
  srand(time(NULL));

  print_header();
  print_timestamp();

  printf("Starting QoS monitoring...\n");

  while(1) {
    network_quality = rand() % 101;

    printf("Network Quality: %d%%\n", network_quality);

    if(network_quality < 60) {
      printf("Warning: Network Quality is below acceptable threshold!\n");
    }

    sleep(WAIT_TIME);
  }

  return 0;
}