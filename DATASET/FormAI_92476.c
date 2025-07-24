//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct {
    pthread_t thread_id;
    int thread_num;
    char *message;
} thread_info_t;

void *thread_main(void *arg) {
    thread_info_t *tinfo = arg;
    printf("Thread %d: %s\n", tinfo->thread_num, tinfo->message);
    return NULL;
}

int main() {
    int num_threads = 5;
    thread_info_t *tinfo;
    pthread_attr_t attr;
    int i, s;
    void *res;
    
    tinfo = calloc(num_threads, sizeof(thread_info_t));
    if (tinfo == NULL) {
        perror("calloc");
        exit(EXIT_FAILURE);
    }

    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

    for (i = 0; i < num_threads; i++) {
        tinfo[i].thread_num = i;
        tinfo[i].message = "Hello, World!";
        s = pthread_create(&tinfo[i].thread_id, &attr, thread_main, &tinfo[i]);
        if (s != 0) {
            perror("pthread_create");
            exit(EXIT_FAILURE);
        }
    }

    pthread_attr_destroy(&attr);

    for (i = 0; i < num_threads; i++) {
        s = pthread_join(tinfo[i].thread_id, &res);
        if (s != 0) {
            perror("pthread_join");
            exit(EXIT_FAILURE);
        }
        printf("Thread %d joined\n", i);
    }

    free(tinfo);
    pthread_exit(NULL);
    return 0;
}