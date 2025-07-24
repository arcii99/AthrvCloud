//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

// Define the maximum size of the message
#define MESSAGE_SIZE 100

// Define the size of the digital watermark
#define WATERMARK_SIZE 10

// Define the number of threads
#define NUM_THREADS 2

// Function prototypes
void *encrypt_message(void *message);
void *embed_watermark(void *watermark);

// Define global variables
char message[MESSAGE_SIZE];
char watermark[WATERMARK_SIZE];

// Define mutex variables
pthread_mutex_t message_mutex;
pthread_mutex_t watermark_mutex;

int main() {

  // Initialize mutex variables
  pthread_mutex_init(&message_mutex, NULL);
  pthread_mutex_init(&watermark_mutex, NULL);

  // Get user input for the message
  printf("Enter a message (up to %d characters):\n", MESSAGE_SIZE-1);
  fgets(message, MESSAGE_SIZE, stdin);

  // Remove the newline character from the message
  message[strcspn(message, "\n")] = '\0';

  // Get user input for the watermark
  printf("Enter a watermark (up to %d characters):\n", WATERMARK_SIZE-1);
  fgets(watermark, WATERMARK_SIZE, stdin);

  // Remove the newline character from the watermark
  watermark[strcspn(watermark, "\n")] = '\0';

  // Create the threads
  pthread_t threads[NUM_THREADS];

  int rc1 = pthread_create(&threads[0], NULL, encrypt_message, (void *)0);
  int rc2 = pthread_create(&threads[1], NULL, embed_watermark, (void *)1);

  // Check for errors creating the threads
  if (rc1 || rc2) {
    printf("Error: unable to create thread(s)\n");
    exit(-1);
  }

  // Wait for the threads to finish
  pthread_join(threads[0], NULL);
  pthread_join(threads[1], NULL);

  // Print the results
  printf("The encrypted message is: %s\n", message);
  printf("The message with the watermark embedded is: %s\n", message);

  // Destroy mutex variables
  pthread_mutex_destroy(&message_mutex);
  pthread_mutex_destroy(&watermark_mutex);

  return 0;
}

// Function to encrypt the message
void *encrypt_message(void *arg) {
  int i;
  char c;

  // Lock the message mutex
  pthread_mutex_lock(&message_mutex);

  // Encrypt the message
  for (i = 0; i < strlen(message); i++) {
    c = message[i];
    c = c + 5;
    message[i] = c;
  }

  // Unlock the message mutex
  pthread_mutex_unlock(&message_mutex);

  pthread_exit(NULL);
}

// Function to embed the watermark
void *embed_watermark(void *arg) {
  int i, j;
  char temp_message[MESSAGE_SIZE + WATERMARK_SIZE];

  // Lock the message and watermark mutexes
  pthread_mutex_lock(&message_mutex);
  pthread_mutex_lock(&watermark_mutex);

  // Copy the message and watermark into a temporary buffer
  strcpy(temp_message, message);
  strcat(temp_message, watermark);

  // Embed the watermark
  for (i = strlen(message), j = 0; j < strlen(watermark); i++, j++) {
    message[i] = watermark[j];
  }

  // Unlock the message and watermark mutexes
  pthread_mutex_unlock(&message_mutex);
  pthread_mutex_unlock(&watermark_mutex);

  pthread_exit(NULL);
}