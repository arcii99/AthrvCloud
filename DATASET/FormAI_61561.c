//FormAI DATASET v1.0 Category: Digital signal processing ; Style: multi-threaded
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 512
#define M_PI 3.14159265358979323846

float input[N];
float output[N];

void *fft(void *thread_id){
    long tid;
    tid = (long)thread_id;
    int start = tid*(N/8);
    int end = start+(N/8);

    for(int i = start; i < end; i++){
        float sum_real = 0.0;
        float sum_imag = 0.0;
        for(int j = 0; j < N; j++){
            float angle = 2 * M_PI * j * i / (float)N;
            sum_real += input[j] * cos(angle);
            sum_imag += -input[j] * sin(angle);
        }
        output[i] = sqrt(pow(sum_real, 2) + pow(sum_imag, 2));
    }
    pthread_exit(NULL);
}

int main(){
    pthread_t threads[8];
    int rc;

    for(int i = 0; i < N; i++){
        input[i] = sin(2*M_PI*i/50);
    }

    for(long t = 0; t < 8; t++){
        rc = pthread_create(&threads[t], NULL, fft, (void *)t);
        if(rc){
            printf("Error:unable to create thread, %d\n", rc);
            exit(-1);
        }
    }

    for(int i =0; i < 8; i++){
        pthread_join(threads[i], NULL);
    }

    printf("Output:\n");
    for(int i = 0; i < N; i++){
        printf("%.2f\n", output[i]);
    }

    pthread_exit(NULL);
}