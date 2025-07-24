//FormAI DATASET v1.0 Category: System administration ; Style: decentralized
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>

void signalHandler(int signalNumber){
    printf("Received signal with number %d\n", signalNumber);
}

int main(){
    signal(SIGINT, signalHandler);
    signal(SIGTERM, signalHandler);
    signal(SIGHUP, signalHandler);

    int i = 0;
    while(1) {
        printf("System is running. Loop number %d\n", i++);
        sleep(1);
    }

    return 0;
}