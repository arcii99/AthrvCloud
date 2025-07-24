//FormAI DATASET v1.0 Category: Smart home light control ; Style: multiplayer
#include <stdio.h>
#include <stdbool.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_LIGHTS 5
#define THREAD_COUNT 3

pthread_mutex_t lock;

struct Light {
  int light_id;
  bool status;
};

struct Light lights[MAX_LIGHTS];

void initializeLights() {
  for (int i = 0; i < MAX_LIGHTS; ++i) {
    lights[i].light_id = i;
    lights[i].status = false;
  }
}

void toggleLight(int light_id) {
  pthread_mutex_lock(&lock);
  lights[light_id].status = !lights[light_id].status;
  printf("Light %d is %s\n", light_id, lights[light_id].status == true ? "ON" : "OFF");
  pthread_mutex_unlock(&lock);
}

void *player(void *arg) {
  int *player_id = (int*)arg;
  int light_id = 0;
  while(true) {
    light_id = rand() % MAX_LIGHTS;
    toggleLight(light_id);
    sleep(1);
  }
  pthread_exit(NULL);
}

int main(int argc, char **argv) {
  int player_ids[THREAD_COUNT] = {};
  initializeLights();
  
  pthread_t threads[THREAD_COUNT];

  pthread_mutex_init(&lock, NULL);

  for (int i = 0; i < THREAD_COUNT; ++i) {
    player_ids[i] = i;
    pthread_create(&threads[i], NULL, player, (void *)&player_ids[i]);
  }

  for (int i = 0; i < THREAD_COUNT; ++i) {
    pthread_join(threads[i], NULL);
  }

  pthread_mutex_destroy(&lock);

  return 0;
}