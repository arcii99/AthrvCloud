//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

int greenState = 0;
int yellowState = 0;
int redState = 1;

void *greenLight(void *arg) {
  while(1) {
    if(greenState) {
      printf("Green Light is On\n");
      sleep(10);
      greenState = 0;
      yellowState = 1;
    }
  }
  pthread_exit(NULL);
}

void *yellowLight(void *arg) {
  while(1) {
    if(yellowState) {
      printf("Yellow Light is On\n");
      sleep(5);
      yellowState = 0;
      redState = 1;
    }
  }
  pthread_exit(NULL);
}

void *redLight(void *arg) {
  while(1) {
    if(redState) {
      printf("Red Light is On\n");
      sleep(15);
      redState = 0;
      greenState = 1;
    }
  }
  pthread_exit(NULL);
}

int main() {
  pthread_t threads[3];
  pthread_create(&threads[0], NULL, greenLight, NULL);
  pthread_create(&threads[1], NULL, yellowLight, NULL);
  pthread_create(&threads[2], NULL, redLight, NULL);

  for(int i = 0; i < 3; i++) {
    pthread_join(threads[i], NULL);
  }

  return 0;
}