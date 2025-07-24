//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <pthread.h>
#include <unistd.h>

typedef enum {
  RED,
  YELLOW,
  GREEN
} TrafficLight;

typedef struct {
  TrafficLight color;
  int duration;
} LightState;

pthread_mutex_t mutex;

void *traffic_light(void *arg) {
  LightState *light_state = (LightState *)arg;

  while (true) {
    pthread_mutex_lock(&mutex);

    switch(light_state->color) {
      case RED:
        printf("Red light\n");
        light_state->color = GREEN;
        light_state->duration = rand() % 6 + 5; // 5-10 seconds
        break;

      case YELLOW:
        printf("Yellow light\n");
        light_state->color = RED;
        light_state->duration = rand() % 4 + 2; // 2-5 seconds
        break;

      case GREEN:
        printf("Green light\n");
        light_state->color = YELLOW;
        light_state->duration = rand() % 6 + 3; // 3-8 seconds
        break;
    }

    pthread_mutex_unlock(&mutex);

    sleep(light_state->duration);
  }

  return NULL;
}

int main() {
  srand(time(NULL));

  LightState light_states[] = {
    { RED, 10 },
    { YELLOW, 5 },
    { GREEN, 15 }
  };

  pthread_t threads[3];
  pthread_mutex_init(&mutex, NULL);

  for (int i = 0; i < 3; i++) {
    pthread_create(&threads[i], NULL, traffic_light, &light_states[i]);
  }

  for (int i = 0; i < 3; i++) {
    pthread_join(threads[i], NULL);
  }

  pthread_mutex_destroy(&mutex);

  return 0;
}