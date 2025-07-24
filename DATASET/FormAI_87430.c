//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 5

pthread_t threads[MAX_THREADS];
pthread_mutex_t crypto_lock;

char* CRYPTO_KEY = "mysecretkey";

void* crypto_function(void* arg)
{
  char* str = (char*) arg;
  printf("Original text: %s\n", str);

  // Simple encryption algorithm
  pthread_mutex_lock(&crypto_lock); // Lock mutex
  for(int i = 0; i < strlen(str); i++) {
    str[i] ^= CRYPTO_KEY[i % strlen(CRYPTO_KEY)];
  }
  pthread_mutex_unlock(&crypto_lock); // Unlock mutex

  printf("Encrypted text: %s\n", str);

  return NULL;
}

int main() {
  char* texts[MAX_THREADS] = {"Hello World", "Lorem Ipsum", "1234567890", "Test123", "This is a secret"};

  if (pthread_mutex_init(&crypto_lock, NULL) != 0) {
    perror("Mutex initialization failed");
    exit(EXIT_FAILURE);
  }

  for(int i = 0; i < MAX_THREADS; i++) {
    int rc = pthread_create(&threads[i], NULL, crypto_function, texts[i]);
    if (rc != 0) {
      perror("Thread creation failed");
      exit(EXIT_FAILURE);
    }
  }

  for(int i = 0; i < MAX_THREADS; i++) {
    int rc = pthread_join(threads[i], NULL);
    if (rc != 0) {
      perror("Thread join failed");
      exit(EXIT_FAILURE);
    }
  }

  pthread_mutex_destroy(&crypto_lock);

  return 0;
}