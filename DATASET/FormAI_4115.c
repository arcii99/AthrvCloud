//FormAI DATASET v1.0 Category: Pattern printing ; Style: multi-threaded
#include <stdio.h>
#include <pthread.h>

void *printC(void *arg) {
    int i;
    for (i = 0; i < 20; i++) {
        printf("C\n");
        fflush(stdout);
        usleep(500000);
    }
    pthread_exit(NULL);
}

void *printPattern(void *arg) {
    int i;
    char pattern[] = " * * * * * * *\n* * * * * * *\n * * * * * * *\n";
    for (i = 0; i < 5; i++) {
        printf("%s", pattern);
        fflush(stdout);
        usleep(500000);
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t cThread, patternThread;

    pthread_create(&cThread, NULL, printC, NULL);
    pthread_create(&patternThread, NULL, printPattern, NULL);

    pthread_join(cThread, NULL);
    pthread_join(patternThread, NULL);
    
    return 0;
}