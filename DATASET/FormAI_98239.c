//FormAI DATASET v1.0 Category: Error handling ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define ERR_MSG_LEN 50

// Function to simulate some time-consuming task
void* someTask(void* arg) {
  int res = rand() % 3; // Random number between 0 and 2
  if (res == 0) {
    // Simulate an error
    return (void*) "Error: Some error occurred";
  } else {
    // Simulate success
    return (void*) "Success: Task completed successfully";
  }
}

int main() {
  pthread_t thread;
  void* result;
  int status;

  // Create the thread for the task
  status = pthread_create(&thread, NULL, someTask, NULL);
  if (status != 0) {
    printf("Error: Failed to create thread\n");
    return 1;
  }

  // Wait for the thread to complete
  status = pthread_join(thread, &result);
  if (status != 0) {
    printf("Error: Failed to join thread\n");
    return 1;
  }

  // Check the result and handle any error
  char* resultStr = (char*) result;
  if (resultStr != NULL) {
    if (resultStr[0] == 'E') {
      printf("Error: %s\n", resultStr + sizeof(char));
      return 1;
    } else {
      printf("Success: %s\n", resultStr + sizeof(char));
    }
  } else {
    printf("Error: Unknown error occurred\n");
    return 1;
  }

  return 0;
}