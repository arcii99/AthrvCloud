//FormAI DATASET v1.0 Category: Date and time ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h> 
#include <pthread.h>
#include <time.h> 

void* printTime(void* arg) {
   time_t curTime;
   struct tm* timeInfo;

   time(&curTime);
   timeInfo = localtime(&curTime);
    
   printf("Current time: %02d:%02d:%02d\n", timeInfo->tm_hour, timeInfo->tm_min, timeInfo->tm_sec);
   pthread_exit(NULL);
}

int main() {
   pthread_t thread1, thread2;
  
   pthread_create(&thread1, NULL, printTime, NULL);
   pthread_create(&thread2, NULL, printTime, NULL);

   pthread_join(thread1, NULL);
   pthread_join(thread2, NULL);

   return 0;
}