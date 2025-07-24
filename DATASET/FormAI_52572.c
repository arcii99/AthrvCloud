//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define NUMBER_OF_LIGHTS 3

// Define the state of each traffic light.
typedef enum {
  GREEN,
  YELLOW,
  RED
} light_state;

// Define the data required by each traffic light.
typedef struct {
  light_state state;
  int duration;
  pthread_mutex_t mutex;
} light_data;

// Define the controller data.
typedef struct {
  light_data lights[NUMBER_OF_LIGHTS];
  int current_light_index;
  pthread_mutex_t mutex;
} controller_data;

// Initialize a traffic light.
void initialize_light(light_data* light, light_state initial_state, int duration) {
  light->state = initial_state;
  light->duration = duration;
  pthread_mutex_init(&light->mutex, NULL);
}

// Set the current light of the controller.
void set_current_light(controller_data* controller, int light_index) {
  pthread_mutex_lock(&controller->mutex);
  controller->current_light_index = light_index;
  pthread_mutex_unlock(&controller->mutex);
}

// Get the current light of the controller.
int get_current_light(controller_data* controller) {
  int current_light_index;
  pthread_mutex_lock(&controller->mutex);
  current_light_index = controller->current_light_index;
  pthread_mutex_unlock(&controller->mutex);
  return current_light_index;
}

// Change the state of a traffic light.
void set_light_state(light_data* light, light_state state) {
  pthread_mutex_lock(&light->mutex);
  light->state = state;
  pthread_mutex_unlock(&light->mutex);
}

// Get the state of a traffic light.
light_state get_light_state(light_data* light) {
  light_state state;
  pthread_mutex_lock(&light->mutex);
  state = light->state;
  pthread_mutex_unlock(&light->mutex);
  return state;
}

// Run a traffic light.
void* run_light(void* arg) {
  // Get the data for the traffic light.
  light_data* light = (light_data*)arg;
  while (1) {
    // Wait for the current duration.
    usleep(light->duration * 1000);

    // Change the state of the traffic light.
    switch (get_light_state(light)) {
      case GREEN:
        set_light_state(light, YELLOW);
        break;
      case YELLOW:
        set_light_state(light, RED);
        break;
      case RED:
        set_light_state(light, GREEN);
        break;
    }
  }
}

// Run a traffic light controller.
void* run_controller(void* arg) {
  // Get the data for the traffic light controller.
  controller_data* controller = (controller_data*)arg;

  // Initialize each traffic light.
  initialize_light(&controller->lights[0], GREEN, 5000);
  initialize_light(&controller->lights[1], RED, 2000);
  initialize_light(&controller->lights[2], RED, 2000);

  // Start each traffic light.
  pthread_t light_threads[NUMBER_OF_LIGHTS];
  for (int i = 0; i < NUMBER_OF_LIGHTS; i++) {
    pthread_create(&light_threads[i], NULL, run_light, &controller->lights[i]);
  }

  // Loop through each traffic light.
  while (1) {
    // Get the current traffic light.
    int current_light_index = get_current_light(controller);

    // Wait for the current duration.
    usleep(controller->lights[current_light_index].duration * 1000);

    // Set the next traffic light.
    current_light_index = (current_light_index + 1) % NUMBER_OF_LIGHTS;
    set_current_light(controller, current_light_index);
  }
}

// Main function.
int main() {
  // Initialize the controller data.
  controller_data controller;
  controller.current_light_index = 0;
  pthread_mutex_init(&controller.mutex, NULL);

  // Start the traffic light controller.
  pthread_t controller_thread;
  pthread_create(&controller_thread, NULL, run_controller, &controller);

  // Loop indefinitely.
  while (1) {}
}