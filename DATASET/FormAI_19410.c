//FormAI DATASET v1.0 Category: Date and time ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>

void *print_time(void * arg);

int main(int argc, char *argv[]) {
   pthread_t tid1, tid2;
   printf("Main thread started.\n");

   // create two threads
   pthread_create(&tid1, NULL, print_time, "Thread 1");
   pthread_create(&tid2, NULL, print_time, "Thread 2");

   // wait for both threads to finish
   pthread_join(tid1, NULL);
   pthread_join(tid2, NULL);
   printf("Main thread ended.\n");
   return 0;
}

void *print_time(void * arg) {
   char *thread_name = (char *) arg;
   printf("%s started.\n", thread_name);

   // get current time and date
   time_t current_time = time(NULL);
   struct tm *tm_info = localtime(&current_time);
   char *time_str = asctime(tm_info);

   // print thread name and time/date
   printf("%s: %s", thread_name, time_str);
   sleep(1);
   printf("%s ended.\n", thread_name);
   return NULL;
}