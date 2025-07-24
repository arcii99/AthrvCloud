//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: curious
/* Welcome to my Threading Library Implementation program! */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

/* Let's define our thread function */
void *myThreadFunc(void *args)
{
  /* Let's print some message */
  printf("I am in thread #%d\n", *(int*)args);
  
  /* Let's sleep for a random time */
  int sleepTime = rand() % 10;
  printf("Sleeping for %d seconds\n", sleepTime);
  sleep(sleepTime);
  
  /* Let's print some message again */
  printf("Thread #%d has finished\n", *(int*)args);
  
  /* Let's return NULL */
  return NULL;
}

/* Let's define our main function */
int main()
{
  /* Let's create an array to hold our thread IDs */
  pthread_t threads[5];
  
  /* Let's create an array to hold our thread arguments */
  int args[5] = {1, 2, 3, 4, 5};
  
  /* Let's create our threads */
  for (int i=0; i<5; i++)
  {
    if (pthread_create(&threads[i], NULL, myThreadFunc, &args[i]) != 0)
    {
      printf("Error creating thread #%d\n", args[i]);
      return 1;
    }
    else
    {
      printf("Thread #%d created successfully\n", args[i]);
    }
  }
  
  /* Let's wait for our threads to finish */
  for (int i=0; i<5; i++)
  {
    if (pthread_join(threads[i], NULL) != 0)
    {
      printf("Error joining thread #%d\n", args[i]);
      return 1;
    }
    else
    {
      printf("Thread #%d joined successfully\n", args[i]);
    }
  }
  
  /* Let's print some final message */
  printf("All threads finished successfully!\n");
  
  /* Let's return 0 */
  return 0;
}