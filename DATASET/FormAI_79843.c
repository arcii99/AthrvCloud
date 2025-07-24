//FormAI DATASET v1.0 Category: Searching algorithm ; Style: multi-threaded
#include <stdio.h>
#include <pthread.h>

#define ARRAY_SIZE 10
int array[ARRAY_SIZE] = {4,2,6,3,8,1,7,5,9,0};
int search_value = 5, found = 0;

struct search_args {
    int *array;
    int start;
    int end;
    int search_value;
};

void* search_thread(void *args) {
    struct search_args *s_args = (struct search_args *) args;
    int *array = s_args->array;
    int start = s_args->start;
    int end = s_args->end;
    int search_value = s_args->search_value;

    for(int i=start; i<end; i++) {
        if(array[i] == search_value) {
            found = 1;
            break;
        }
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t search_threads[2];
    struct search_args s_args[2];

    for(int i=0; i<2; i++) {
        s_args[i].array = array;
        s_args[i].start = i * ARRAY_SIZE / 2;
        s_args[i].end = (i+1) * ARRAY_SIZE / 2;
        s_args[i].search_value = search_value;
        pthread_create(&search_threads[i], NULL, search_thread, (void *) &s_args[i]);
    }

    for(int i=0; i<2; i++) {
        pthread_join(search_threads[i], NULL);
    }

    if(found) {
        printf("Value found in array\n");
    } else {
        printf("Value not found in array\n");
    }

    return 0;
}