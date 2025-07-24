//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: Claude Shannon
#include <stdio.h>
#include <pthread.h>

void* print_message(void* msg)
{
  printf("%s\n", (char*) msg);
  return NULL;
}

int main()
{
  pthread_t thread;
  char* message = "Hello, World!";
  
  if (pthread_create(&thread, NULL, print_message, (void*) message) != 0)
  {
    perror("pthread_create error");
    return -1;
  }
  
  if (pthread_join(thread, NULL) != 0)
  {
    perror("pthread_join error");
    return -1;
  }
  
  return 0;
}