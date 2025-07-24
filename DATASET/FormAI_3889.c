//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL));
  int download_speed = (rand() % 100) + 1;
  int upload_speed = (rand() % 100) + 1;

  printf("Your Internet Speed:\n");
  printf("Download speed: %d Mbps\n", download_speed);
  printf("Upload speed: %d Mbps\n\n", upload_speed);

  if(download_speed > 50 && upload_speed > 50) {
    printf("Your Internet speed is excellent! You can easily stream videos and play online games without any issues.\n");
  }
  else if((download_speed > 30 && download_speed <= 50) && (upload_speed > 30 && upload_speed <= 50)) {
    printf("Your Internet speed is good. You can stream videos and play online games but might experience some buffering and lag.\n");
  }
  else if((download_speed > 10 && download_speed <= 30) && (upload_speed > 10 && upload_speed <= 30)) {
    printf("Your Internet speed is average. You may experience buffering when streaming videos and playing online games.\n");
  }
  else {
    printf("Your Internet speed is poor. You may experience significant buffering when streaming videos and games may be unplayable.\n");
  }

  return 0;
}