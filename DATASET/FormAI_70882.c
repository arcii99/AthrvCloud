//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: Ken Thompson
#include <pthread.h>
#include <stdio.h>

pthread_mutex_t count_mutex;
pthread_cond_t condition_var;

void *functionCount1();
void *functionCount2();
int count = 0;
#define COUNT_DONE  10
#define COUNT_HALT1 3
#define COUNT_HALT2 6

int main()
{
   pthread_t thread1, thread2;

   pthread_mutex_init(&count_mutex, NULL);
   pthread_cond_init(&condition_var, NULL);

   pthread_create(&thread1, NULL, &functionCount1, NULL);
   pthread_create(&thread2, NULL, &functionCount2, NULL);

   pthread_join(thread1, NULL);
   pthread_join(thread2, NULL);

   pthread_mutex_destroy(&count_mutex);
   pthread_cond_destroy(&condition_var);

   return 0;
}

void *functionCount1()
{

   for(;;)
   {
      pthread_mutex_lock(&count_mutex);

      while( count >= COUNT_HALT1 && count <= COUNT_HALT2 )
      {
         pthread_cond_wait(&condition_var, &count_mutex);
      }

      count++;
      printf("Counter value functionCount1: %d\n",count);

      if(count >= COUNT_DONE)
      {
         pthread_mutex_unlock(&count_mutex);
         return(NULL);
      }

      pthread_mutex_unlock(&count_mutex);

      if(count >= COUNT_HALT1 && count <= COUNT_HALT2)
      {
         pthread_cond_signal(&condition_var);
      }

      sleep(1);
   }
}

void *functionCount2()
{

   for(;;)
   {
      pthread_mutex_lock(&count_mutex);

      while( count < COUNT_HALT1 || count > COUNT_HALT2 )
      {
         pthread_cond_wait(&condition_var, &count_mutex);
      }

      count++;
      printf("Counter value functionCount2: %d\n",count);

      if(count >= COUNT_DONE)
      {
         pthread_mutex_unlock(&count_mutex);
         return(NULL);
      }

      pthread_mutex_unlock(&count_mutex);
      pthread_cond_signal(&condition_var);
      sleep(1);

   }

}