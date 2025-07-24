//FormAI DATASET v1.0 Category: System boot optimizer ; Style: scalable
#include<time.h>
#include<stdlib.h>
#include<stdio.h>

void optimize_boot(){
    printf("Optimizing boot process...\n");
    srand(time(NULL));
    int time_to_wait = rand() % 10 + 1;
    printf("Waiting for %d seconds...\n", time_to_wait);
    sleep(time_to_wait);
    printf("Boot optimized!\n");
}

int main(){
    optimize_boot();

    return 0;
}