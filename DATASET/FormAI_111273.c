//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

int main() {
    int red = 1;
    int green = 0;
    int yellow = 0;
    
    while(1) {
        pthread_mutex_lock(&mutex);
        
        if(red) {
            printf("Red Light On\n");
            green = 0;
            yellow = 1;
            sleep(5);
        }
        else if(yellow) {
            printf("Yellow Light On\n");
            red = 0;
            green = 1;
            yellow = 0;
            sleep(3);
        }
        else if(green) {
            printf("Green Light On\n");
            red = 1;
            green = 0;
            sleep(5);
        }
        
        pthread_mutex_unlock(&mutex);
    }
    
    return 0;
}