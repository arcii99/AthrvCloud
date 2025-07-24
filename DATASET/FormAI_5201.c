//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: Cryptic
#include <stdio.h>
#include <pthread.h>

#define BUF_SIZE 5            //define buffer size as 5
char buffer[BUF_SIZE];        //create a character buffer of size 5
int count = 0;                //track the number of items in the buffer
pthread_cond_t pro_cond;      //producer condition variable
pthread_cond_t con_cond;      //consumer condition variable
pthread_mutex_t mutex;        //mutex lock

void *producer(void *param) {
  char ch = 'A';              //initialize character to 'A'
  while(1) {                  //infinite loop, will only break from main
    pthread_mutex_lock(&mutex);
    while(count >= BUF_SIZE)   //buffer is full, wait for consumer
      pthread_cond_wait(&pro_cond, &mutex);
    printf("Produced: %c\n", ch);
    buffer[count++] = ch++;   //add character to buffer
    if(ch > 'Z') ch = 'A';    //reset character to 'A' after 'Z'
    pthread_cond_signal(&con_cond); //signal consumer
    pthread_mutex_unlock(&mutex);
  }
}

void *consumer(void *param) {
  while(1) {                  //infinite loop, will only break from main
    pthread_mutex_lock(&mutex);
    while(count == 0)         //buffer is empty, wait for producer
      pthread_cond_wait(&con_cond, &mutex);
    printf("Consumed: %c\n", buffer[--count]); //remove item from buffer
    pthread_cond_signal(&pro_cond);            //signal producer
    pthread_mutex_unlock(&mutex);
  }
}

int main() {
  pthread_t prod, con;      //create two threads for producer and consumer
  pthread_cond_init(&pro_cond, NULL); //initialize condition variables
  pthread_cond_init(&con_cond, NULL);
  pthread_mutex_init(&mutex, NULL);  //initialize mutex lock
  pthread_create(&prod, NULL, producer, NULL); //create threads
  pthread_create(&con, NULL, consumer, NULL);
  pthread_join(prod, NULL); //wait for threads to complete
  pthread_join(con, NULL);
  return 0;
}