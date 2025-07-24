//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>

#define RED 1
#define YELLOW 2
#define GREEN 3

int current_signal;
pthread_mutex_t mutex;

void *traffic_control(void *data) {
    while (true) {
        pthread_mutex_lock(&mutex);
        switch (current_signal) {
            case RED:
                printf("Red Signal - Stop!\n");
                sleep(5);
                current_signal = GREEN;
                break;

            case YELLOW:
                printf("Yellow Signal - Prepare to Stop!\n");
                sleep(2);
                current_signal = RED;
                break;

            case GREEN:
                printf("Green Signal - Go!\n");
                sleep(5);
                current_signal = YELLOW;
                break;
        }
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

int main(int argc, char *argv[]) {
    current_signal = RED;
    pthread_t thread_id;
    pthread_create(&thread_id, NULL, traffic_control, NULL);
    while (true) {
        char input[10];
        printf("To quit the program, type 'q'\n");
        printf("To view current signal state, type 's'\n");
        fgets(input, sizeof(input), stdin);
        if (input[0] == 'q') {
            pthread_cancel(thread_id);
            pthread_join(thread_id, NULL);
            exit(EXIT_SUCCESS);
        } else if (input[0] == 's') {
            pthread_mutex_lock(&mutex);
            switch (current_signal) {
                case RED:
                    printf("Current signal state: RED\n");
                    break;
                    
                case YELLOW:
                    printf("Current signal state: YELLOW\n");
                    break;
                    
                case GREEN:
                    printf("Current signal state: GREEN\n");
                    break;
            }
            pthread_mutex_unlock(&mutex);
        } else {
            printf("Invalid input\n");
        }
    }
    return 0;
}