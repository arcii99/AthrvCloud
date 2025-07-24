//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

struct thread_data {
    int thread_id;
    int thread_param;
    char *thread_msg;
};

void *thread_function(void *arg) {
    struct thread_data *my_data;
    my_data = (struct thread_data *) arg;
    printf("Thread ID: %d\n", my_data->thread_id);
    printf("Thread Param: %d\n", my_data->thread_param);
    printf("Thread Msg: %s\n", my_data->thread_msg);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[2];
    int rc;
    int i;
    struct thread_data td[2];

    for (i = 0; i < 2; i++) {
        printf("Creating thread %d\n", i);
        td[i].thread_id = i;
        td[i].thread_param = i + 1;
        td[i].thread_msg = "Hello from thread";
        rc = pthread_create(&threads[i], NULL, thread_function, (void *) &td[i]);

        if (rc) {
            printf("Failed to create thread %d\n", i);
            exit(1);
        }
    }

    pthread_join(threads[0], NULL);
    pthread_join(threads[1], NULL);

    return 0;
}