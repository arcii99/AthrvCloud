//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

void init(char **arr, int size){
    for(int i = 0; i < size; i++){
        arr[i] = malloc(sizeof(char)*200);
    }
}

void cleanup(char **arr, int size){
    for(int i = 0; i < size; i++){
        free(arr[i]);
    }
    free(arr);
}

void fill_array(char **arr){
    for(int i = 0; i < 10; i++){
        sprintf(arr[i], "Item %d", i);
    }
}

void print_array(char **arr){
    for(int i = 0; i < 10; i++){
        printf("%s\n", arr[i]);
    }
}

int main(){
    char **arr = malloc(sizeof(char*)*10);
    init(arr, 10);
    fill_array(arr);
    print_array(arr);
    cleanup(arr, 10);
    return 0;
}