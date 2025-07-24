//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: multi-threaded
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_STRING_LENGTH 100

// Function that analyzes the sentiment of a given sentence
void analyzeSentiment(char* sentence) {
  int score = 0;
  char* token = strtok(sentence, " ");
  
  while (token != NULL) {
    // Check if the token represents a positive or negative sentiment
    if (strcmp(token, "good") == 0 || strcmp(token, "great") == 0 || strcmp(token, "awesome") == 0 || strcmp(token, "excellent") == 0) {
      score++;
    } else if (strcmp(token, "bad") == 0 || strcmp(token, "terrible") == 0 || strcmp(token, "awful") == 0 || strcmp(token, "horrible") == 0) {
      score--;
    }

    token = strtok(NULL, " ");
  }

  // Print the overall sentiment score of the sentence
  printf("This sentence has a sentiment score of %d.\n", score);
}

// Function executed by each thread
void* analyzeThread(void* arg) {
  char* sentence = (char*) arg;
  
  analyzeSentiment(sentence);
  
  // Exit the thread
  pthread_exit(NULL);
}

int main() {
  // Array of sentences to analyze
  char sentences[MAX_THREADS][MAX_STRING_LENGTH] = 
    {"The movie was great!", 
     "I had a terrible experience at the restaurant.",
     "The weather today is awesome.",
     "Don't waste your money on that game, it's horrible.",
     "The service at this hotel is excellent!",
     "I feel bad for not being able to attend the party."};

  // Array of threads
  pthread_t threads[MAX_THREADS];

  // Create a thread for each sentence
  for (int i = 0; i < MAX_THREADS; i++) {
    if (pthread_create(&threads[i], NULL, analyzeThread, (void*) sentences[i]) != 0) {
      printf("Error creating thread for sentence %d.\n", i+1);
      exit(1);
    }
  }

  // Wait for all threads to finish
  for (int i = 0; i < MAX_THREADS; i++) {
    if (pthread_join(threads[i], NULL) != 0) {
      printf("Error joining thread for sentence %d.\n", i+1);
      exit(1);
    }
  }

  return 0;
}