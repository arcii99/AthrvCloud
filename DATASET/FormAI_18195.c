//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL));
  
  printf("Initializing Intrusion Detection System...\n");
  printf("...\n");
  printf("...\n");
  printf("System active.\n");
  
  while(1) {
    int random_num = rand() % 10;
    if (random_num == 5) {
      printf("Intrusion detected! Initiating response protocol...\n");
      int response = rand() % 3;
      if (response == 0) {
        printf("Deploying army of penguins to the location.\n");
      } else if (response == 1) {
        printf("Launching giant cupcakes at the intruder.\n");
      } else if (response == 2) {
        printf("Releasing hypnotic dancing elephants to distract the intruder.\n");
      }
     printf("Intruder neutralized!\n");
    }
    
    int sleep_time = rand() % 5;
    printf("System sleeping for %d seconds...\n", sleep_time);
    sleep(sleep_time);
  }
  
  return 0;
}