//FormAI DATASET v1.0 Category: Arithmetic ; Style: multi-threaded
#include <stdio.h>
#include <pthread.h>

void* add(void *arg){
    int a = *(int*)arg;
    int b = *(int*)(arg+sizeof(int));
    int *c = malloc(sizeof(int));
    *c = a + b;
    return (void*)c;
}

void* subtract(void *arg){
    int a = *(int*)arg;
    int b = *(int*)(arg+sizeof(int));
    int *c = malloc(sizeof(int));
    *c = a - b;
    return (void*)c;
}

int main(){
    int x = 5, y = 3;
    pthread_t add_thread, sub_thread;
    void *add_result, *sub_result;
    int add_arguments[2] = {x, y};
    int sub_arguments[2] = {x, y};

    pthread_create(&add_thread, NULL, add, (void*)add_arguments);
    pthread_create(&sub_thread, NULL, subtract, (void*)sub_arguments);

    pthread_join(add_thread, &add_result);
    pthread_join(sub_thread, &sub_result);

    printf("The sum of %d and %d is %d\n", x, y, *(int*)add_result);
    printf("The difference between %d and %d is %d\n", x, y, *(int*)sub_result);

    free(add_result);
    free(sub_result);

    return 0;
}