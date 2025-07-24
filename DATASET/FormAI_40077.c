//FormAI DATASET v1.0 Category: File Synchronizer ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUFFER_SIZE 256

void* sync_file(void *arg);

int main(int argc, char **argv) {
  // Verify that the correct arguments are entered
  if (argc != 3) {
    printf("Usage: %s <source file> <target file>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  // Open source file for reading
  int source_fd = open(argv[1], O_RDONLY);
  if (source_fd == -1) {
    perror("open source file");
    exit(EXIT_FAILURE);
  }

  // Open target file for writing
  int target_fd = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0644);
  if (target_fd == -1) {
    perror("open target file");
    close(source_fd);
    exit(EXIT_FAILURE);
  }

  // Create two threads to sync the files
  pthread_t thread1, thread2;
  int rc1 = pthread_create(&thread1, NULL, sync_file, (void *)&source_fd);
  int rc2 = pthread_create(&thread2, NULL, sync_file, (void *)&target_fd);

  // Verify that the threads were created successfully
  if (rc1 || rc2) {
    printf("Error: Failed to create threads.\n");
    close(source_fd);
    close(target_fd);
    exit(EXIT_FAILURE);
  }

  // Wait for the threads to finish
  pthread_join(thread1, NULL);
  pthread_join(thread2, NULL);

  // Close the files
  close(source_fd);
  close(target_fd);

  printf("Files synchronized successfully!\n");

  return 0;
}

// Function to synchronize the files
void* sync_file(void *arg) {
  int fd = *((int *)arg);
  char buffer[BUFFER_SIZE];
  int bytes_read;

  // Read from the file and write to the other file
  while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0) {
    if (write(fd == 0 ? 1 : 0, buffer, bytes_read) != bytes_read) {
      printf("Error: write failed.\n");
      pthread_exit(NULL);
    }
  }

  // Check for read errors
  if (bytes_read == -1) {
    printf("Error: read failed.\n");
  }

  pthread_exit(NULL);
}