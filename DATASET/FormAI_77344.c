//FormAI DATASET v1.0 Category: Temperature monitor ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <pthread.h>

#define BUFFER_SIZE 10
#define MAX_THREADS 5

double temperature[BUFFER_SIZE];
int front = -1;
int rear = -1;

pthread_mutex_t mutex;
pthread_cond_t cv;

void addTemperature(double temp) {
    pthread_mutex_lock(&mutex);
    if((front == 0 && rear == BUFFER_SIZE-1) || front == rear+1) {
        printf("Temperature buffer is full. Removing oldest entry.\n");
        if(front == rear) {
            rear = -1;
            front = -1;
        } else {
            front = (front+1) % BUFFER_SIZE;
        }
    }
    if(front == -1) {
        front = 0;
        rear = 0;
        temperature[rear] = temp;
    } else {
        rear = (rear+1) % BUFFER_SIZE;
        temperature[rear] = temp;
    }
    printf("Added temperature %.2lf to the buffer.\n", temp);
    pthread_cond_broadcast(&cv);
    pthread_mutex_unlock(&mutex);
}

double getAverageTemperature() {
    double sum = 0;
    int i, count = 1;
    for(i = front; i != rear; i = (i+1) % BUFFER_SIZE) {
        sum += temperature[i];
        count++;
    }
    sum += temperature[i];
    printf("Average temperature is %.2lf.\n", sum/count);
    return sum/count;
}

void* temperatureMonitoring(void* arg) {
    int fd = open("/sys/class/thermal/thermal_zone0/temp", O_RDONLY);
    double temp;
    while(1) {
        read(fd, &temp, sizeof(double));
        temp /= 1000;
        addTemperature(temp);
        sleep(1);
    }
    return NULL;
}

void* temperatureControl(void* arg) {
    double averageTemp;
    while(1) {
        pthread_mutex_lock(&mutex);
        while(front == -1) {
            pthread_cond_wait(&cv, &mutex);
        }
        pthread_mutex_unlock(&mutex);
        averageTemp = getAverageTemperature();
        if(averageTemp >= 40) {
            printf("Temperature is very high (%.2lf). Cooling down the system...\n", averageTemp);
        } else if(averageTemp <= 20) {
            printf("Temperature is very low (%.2lf). Warming up the system...\n", averageTemp);
        } else {
            printf("Temperature is normal (%.2lf).\n", averageTemp);
        }
        sleep(5);
    }
    return NULL;
}

int main() {
    pthread_t threadT[MAX_THREADS];
    int i, rc;
    for(i = 0; i < MAX_THREADS; i++) {
        if(i == 0) {
            rc = pthread_create(&threadT[i], NULL, temperatureMonitoring, NULL);
            if(rc) {
                printf("Error:unable to create thread, %d\n", rc);
                exit(-1);
            }
        } else {
            rc = pthread_create(&threadT[i], NULL, temperatureControl, NULL);
            if(rc) {
                printf("Error:unable to create thread, %d\n", rc);
                exit(-1);
            }
        }
    }
    for(i = 0; i < MAX_THREADS; i++) {
        pthread_join(threadT[i], NULL);
    }
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cv);
    return 0;
}