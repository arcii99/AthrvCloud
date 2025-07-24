//FormAI DATASET v1.0 Category: Pattern printing ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *printC(void *arg) {
    for (int i = 0; i < 10; i++) {
        printf(" CCCCC\n");
    }
    return NULL;
}

void *printPatt1(void *arg) {
    for (int i = 0; i < 5; i++) {
        printf("   CCC\n");
        printf("  CC  \n");
        printf(" CC   \n");
    }
    return NULL;
}

void *printPatt2(void *arg) {
    for (int i = 0; i < 5; i++) {
        printf("CC   \n");
        printf(" CC  \n");
        printf("  CCC\n");
    }
    return NULL;
}

int main() {
    pthread_t c_thread, patt1_thread, patt2_thread;
    
    pthread_create(&c_thread, NULL, printC, NULL);
    pthread_create(&patt1_thread, NULL, printPatt1, NULL);
    pthread_create(&patt2_thread, NULL, printPatt2, NULL);
    
    pthread_join(c_thread, NULL);
    pthread_join(patt1_thread, NULL);
    pthread_join(patt2_thread, NULL);
    
    return 0;
}