//FormAI DATASET v1.0 Category: Recursive ; Style: multi-threaded
#include <stdio.h>
#include <pthread.h>

void *recursive_func(void *arg) {
    int num = *(int *)arg;
    if(num < 1) {
        pthread_exit(NULL);
    }
    printf("%d\n", num);
    num--;
    pthread_t tid;
    pthread_create(&tid, NULL, recursive_func, &num);
    pthread_join(tid, NULL);
    pthread_exit(NULL);
}

int main() {
    int start_num = 10;
    pthread_t tid;
    pthread_create(&tid, NULL, recursive_func, &start_num);
    pthread_join(tid, NULL);
    return 0;
}