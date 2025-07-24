//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){

    printf("Welcome to the C RAM Usage Monitor!\n\n");

    while(1){

        char* buffer = (char*) malloc(sizeof(char)*1024*1024*1024);
        // allocate 1 GB of memory

        if(buffer == NULL){
            printf("Error: Unable to allocate memory!\n");
            exit(1);
        }

        float usage = (float) sizeof(buffer)/(1024*1024*1024);
        // calculate current usage

        printf("Current RAM Usage: %.2f GB\n", usage);

        free(buffer);
        // free the allocated memory

        sleep(1);
        // wait for 1 second
    }

    return 0;
}