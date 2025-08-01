//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: enthusiastic
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

void *runner(void *param);    /* the thread */

int main(int argc, char *argv[]) {
    pthread_t tid; /* the thread identifier */
    pthread_attr_t attr;  /* set of attributes for the thread */

    if (argc != 2) {
        fprintf(stderr, "usage: %s <integer value>\n", argv[0]);
        return -1;
    }

    if (atoi(argv[1]) < 0) {
        fprintf(stderr, "%d must be >= 0\n", atoi(argv[1]));
        return -1;
    }

    /* get the default attributes */
    pthread_attr_init(&attr);

    /* create the thread */
    pthread_create(&tid, &attr, runner, argv[1]);

    /* now wait for the thread to exit */
    pthread_join(tid, NULL);

    printf("Thread %ld finished\n", tid);

    return 0;
}

/* The thread will begin control in this function */
void *runner(void *param) {
    int i, upper = atoi(param);
    if (upper > 0) {
        for (i = 1; i <= upper; i++)
        printf("runner: %d\n",i);
    }
    pthread_exit(0);
}