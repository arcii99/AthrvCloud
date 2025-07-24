//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: multi-threaded
#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 4

pthread_mutex_t mutex;
char* alien_language = "Zxkyurptclo";

void *translate(void *tid) {
  long thread_id = (long)tid;
  int i, j, k;

  pthread_mutex_lock(&mutex); // Lock the mutex to ensure atomic access to the alien language
  printf("Thread %ld is translating...\n", thread_id);

  for (i = 0; i < NUM_THREADS; i++) {
    for (j = i; j < 10; j += NUM_THREADS) {
      for (k = j; k < j + NUM_THREADS && k < 10; k++) {
        printf("%c", alien_language[k]);
      }
      printf(" ");
    }
    printf("\n");
  }

  pthread_mutex_unlock(&mutex); // Release the mutex

  pthread_exit(NULL);
}

int main() {
  pthread_t threads[NUM_THREADS];
  pthread_mutex_init(&mutex, NULL);

  int rc;
  long t;
  for (t = 0; t < NUM_THREADS; t++) {
    printf("Creating thread %ld\n", t);
    rc = pthread_create(&threads[t], NULL, translate, (void *)t);
    if (rc) {
      printf("ERROR: Return code from pthread_create() is %d\n", rc);
      return 1;
    }
  }

  for (t = 0; t < NUM_THREADS; t++) {
    rc = pthread_join(threads[t], NULL);
    if (rc) {
      printf("ERROR: Return code from pthread_join() is %d\n", rc);
      return 1;
    }
  }

  pthread_mutex_destroy(&mutex);

  return 0;
}