//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main() {
  int ping_rate = 500;  // in milliseconds
  int packet_loss_rate; // in percentage
  int download_speed;   // in Mbps
  int upload_speed;     // in Mbps
  int qos_score;        // out of 10
  srand(time(NULL));

  while (1) {
    packet_loss_rate = rand() % 11; // generate random packet loss rate from 0-10%
    download_speed = rand() % 101;  // generate random download speed from 0-100 Mbps
    upload_speed = rand() % 101;    // generate random upload speed from 0-100 Mbps

    qos_score = 10 - packet_loss_rate/2 - download_speed/10 - upload_speed/10; // calculate QoS score

    printf("Network Quality of Service:\n");
    printf("---------------------------\n");
    printf("Packet Loss Rate: %d%%\n", packet_loss_rate);
    printf("Download Speed: %d Mbps\n", download_speed);
    printf("Upload Speed: %d Mbps\n", upload_speed);
    printf("QoS Score: %d/10\n", qos_score);
    printf("---------------------------\n\n");

    usleep(ping_rate * 1000); // wait for ping rate before generating new QoS values
  }

  return 0;
}