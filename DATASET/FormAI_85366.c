//FormAI DATASET v1.0 Category: Memory management ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *myAllocate(size_t size){
    void *ptr = malloc(size);

    if(ptr == NULL){
        puts("Out of memory!");
        exit(1);
    }

    return ptr;
}

void *myReallocate(void *ptr, size_t size){
    ptr = realloc(ptr, size);

    if(ptr == NULL){
        puts("Out of memory!");
        exit(1);
    }

    return ptr;
}

void myFree(void *ptr){
    if(ptr != NULL){
        free(ptr);
        puts("Memory freed!");
    } else {
        puts("Null pointer passed to free!");
    }
}

int main(){
    char *string = NULL;

    string = (char *) myAllocate(20 * sizeof(char));
    strcpy(string, "Hello world!");
    printf("Allocated string: %s\n", string);

    string = (char *) myReallocate(string, 30 * sizeof(char));
    strcat(string, " How are you?");
    printf("Realocated string: %s\n", string);

    myFree(string);

    return 0;
}