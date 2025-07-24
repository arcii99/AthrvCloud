//FormAI DATASET v1.0 Category: System event logger ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define MAX_EVENTS 1000

pthread_mutex_t mutex;
int event_count = 0;
char* events[MAX_EVENTS];

void log_event(char* event) {
  pthread_mutex_lock(&mutex);
  if (event_count < MAX_EVENTS) {
    events[event_count] = event;
    event_count++;
  }
  pthread_mutex_unlock(&mutex);
}

void* worker(void* arg) {
  int i;
  for (i=0; i<10; i++) {
    time_t now = time(NULL);
    char* event = malloc(sizeof(now) + 50);
    sprintf(event, "Event %d occurred at %s", i+1, ctime(&now));
    log_event(event);
    printf("Event %d logged\n", i+1);
    sleep(1);
  }
  return NULL;
}

int main(int argc, char** argv) {
  int i;
  pthread_t workers[3];

  if (pthread_mutex_init(&mutex, NULL) != 0) {
    printf("Mutex initialization failed\n");
    return 1;
  }

  for (i=0; i<3; i++) {
    pthread_create(&workers[i], NULL, worker, NULL);
  }

  for (i=0; i<3; i++) {
    pthread_join(workers[i], NULL);
  }

  pthread_mutex_destroy(&mutex);

  printf("\n\nEvent Log:\n\n");

  for (i=0; i<event_count; i++) {
    printf("%s\n", events[i]);
    free(events[i]);
  }

  return 0;
}