//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: multi-threaded
#include <stdio.h>
#include <pthread.h>

void* generateArt(void* arg) {
    char c = *(char *)arg;
    switch(c) {
        case 'a':
            printf("      /\\      \n");
            printf("     /  \\     \n");
            printf("    /    \\    \n");
            printf("   /------\\   \n");
            printf("  /        \\  \n");
            printf(" /          \\ \n");
            break;
        case 'b':
            printf("-----------  \n");
            printf("|          \\ \n");
            printf("--------   |\n");
            printf("|         \\ |\n");
            printf("--------   |\n");
            printf("|          / \n");
            printf("-----------  \n");
            break;
        // Add more letters here
    }
    pthread_exit(NULL);
}

int main () {
    char letters[3] = {'a', 'b', 'c'};
    pthread_t threads[3];
    int rc;
    long t;

    for (t = 0; t < 3; t++) {
        printf("Creating thread %ld\n", t);
        rc = pthread_create(&threads[t], NULL, generateArt, (void *)&letters[t]);
        if (rc) {
            printf("ERROR: return code from pthread_create() is %d\n", rc);
            return 1;
        }
    }

    pthread_exit(NULL);
}