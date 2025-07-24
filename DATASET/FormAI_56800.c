//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: multi-threaded
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <sys/types.h>
#include <unistd.h>

#define MB (1024 * 1024)

void* memory_usage_monitor(void* arg) {
  int* ram_usage = (int*) arg;

  while (1) {
    FILE* fp = fopen("/proc/self/status", "r");

    if (fp == NULL) {
      perror("Error: ");
      return NULL;
    }

    char line[128];

    while (fgets(line, 128, fp) != NULL) {
      if (strncmp(line, "VmRSS:", 6) == 0) {
        int value;
        if (sscanf(line, "VmRSS: %d kB", &value) == 1) {
          *ram_usage = value / 1024;
        }
        break;
      }
    }
    
    fclose(fp);
    sleep(1);
  }
}

int main() {
  int ram_usage = 0;
  pthread_t thread_id;
  
  printf("Starting RAM usage monitor...\n");
  
  if (pthread_create(&thread_id, NULL, memory_usage_monitor, &ram_usage) != 0) {
    perror("Failed to create thread.");
    return 1;
  }

  while (1) {
    printf("Current RAM usage: %d MB\n", ram_usage);
    sleep(2);
  }

  pthread_join(thread_id, NULL);
  return 0;
}