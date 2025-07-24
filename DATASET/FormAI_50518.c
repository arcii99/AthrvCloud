//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* printChar(void* ch) {
    char* myChar = (char*) ch;
    for (int i = 0; i < 20; i++) {
        printf("%c", *myChar);
        fflush(stdout);
        int waitTime = rand() % 1000000;
        usleep(waitTime);
    }
    return NULL;
}

void* printNum(void* num) {
    int* myNum = (int*) num;
    for (int i = 0; i < 10; i++) {
        printf("%d ", *myNum);
        fflush(stdout);
        int waitTime = rand() % 1000000;
        usleep(waitTime);
    }
    return NULL;
}

int main() {
    pthread_t tid1, tid2;
    char ch = '#';
    int num = 5;
    pthread_create(&tid1, NULL, printChar, &ch);
    pthread_create(&tid2, NULL, printNum, &num);
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    return 0;
}