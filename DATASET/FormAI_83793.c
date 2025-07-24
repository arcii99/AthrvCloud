//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 3
#define RED_LIGHT_TIME 5
#define YELLOW_LIGHT_TIME 2
#define GREEN_LIGHT_TIME 5

int current_light = 0;

void* Red_Light_Thread(void* arg) {
  while(1) {
    current_light = 0;
    printf("RED light ON\n");
    sleep(RED_LIGHT_TIME);
  }
  return NULL;
}

void* Yellow_Light_Thread(void* arg) {
  while(1) {
    current_light = 1;
    printf("YELLOW light ON\n");
    sleep(YELLOW_LIGHT_TIME);
  }
  return NULL;
}

void* Green_Light_Thread(void* arg) {
  while(1) {
    current_light = 2;
    printf("GREEN light ON\n");
    sleep(GREEN_LIGHT_TIME);
  }
  return NULL;
}

int main(int argc, char *argv[]) {
  pthread_t threads[NUM_THREADS];
  int rc;

  rc = pthread_create(&threads[0], NULL, Red_Light_Thread, NULL);
  if (rc) {
    printf("ERROR; return code from pthread_create() is %d\n", rc);
    exit(-1);
  }

  rc = pthread_create(&threads[1], NULL, Yellow_Light_Thread, NULL);
  if (rc) {
    printf("ERROR; return code from pthread_create() is %d\n", rc);
    exit(-1);
  }

  rc = pthread_create(&threads[2], NULL, Green_Light_Thread, NULL);
  if (rc) {
    printf("ERROR; return code from pthread_create() is %d\n", rc);
    exit(-1);
  }

  while(1) {
    if(current_light == 0) {
      printf("STOP\n");
    }
    if(current_light == 1) {
      printf("CAUTION\n");
    }
    if(current_light ==2) {
      printf("GO\n");
    }
  }

  pthread_exit(NULL);
  return 0;
}