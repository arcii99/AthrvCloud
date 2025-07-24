//FormAI DATASET v1.0 Category: Searching algorithm ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    int size = 100;
    int key = rand() % size;
    int array[size];

    for(int i = 0; i < size; i++) {
        array[i] = rand() % size;
    }

    int found = 0;
    for(int i = 0; i < size; i++) {
        if(key == array[i]) {
            found = 1;
            printf("Found key %d at index %d\n", key, i);
            break;
        }
    }

    if(!found) {
        printf("Key not found!\n");
    }

    return 0;
}