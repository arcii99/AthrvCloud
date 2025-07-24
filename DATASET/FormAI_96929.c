//FormAI DATASET v1.0 Category: Word Count Tool ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_THREADS 10

typedef struct {
  char *text;
  int count;
} WordCount;

pthread_mutex_t mutex;
WordCount word_count[MAX_THREADS];
int num_threads = 0;

void *count_words(void *args) {
  int i, j, chunk_size;
  WordCount *word_count_ptr;

  word_count_ptr = (WordCount *)args;

  chunk_size = strlen(word_count_ptr->text) / num_threads;

  for (i = 0; i < num_threads; i++) {
    for (j = i * chunk_size; j < (i + 1) * chunk_size && j < strlen(word_count_ptr->text); j++) {
      if (word_count_ptr->text[j] == 'c' || word_count_ptr->text[j] == 'C') {
        pthread_mutex_lock(&mutex);
        word_count_ptr->count++;
        pthread_mutex_unlock(&mutex);
      }
    }
  }

  pthread_exit(NULL);
}

void run_word_count(char *text) {
  pthread_t threads[MAX_THREADS];
  int i;

  pthread_mutex_init(&mutex, NULL);

  num_threads = strlen(text) < MAX_THREADS ? strlen(text) : MAX_THREADS;

  for (i = 0; i < num_threads; i++) {
    word_count[i].text = text;
    word_count[i].count = 0;
    pthread_create(&threads[i], NULL, count_words, &word_count[i]);
  }

  for (i = 0; i < num_threads; i++) {
    pthread_join(threads[i], NULL);
  }

  pthread_mutex_destroy(&mutex);

  int total_count = 0;
  for (i = 0; i < num_threads; i++) {
    total_count += word_count[i].count;
  }

  printf("'%c' count: %d\n", 'c', total_count);
}

int main() {
  char *text = "C programming is a powerful language for developing software.";
  run_word_count(text);
  return 0;
}