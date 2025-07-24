//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 2
#define BUFFER_SIZE 1024

char buffer[BUFFER_SIZE];

void* translate(void* thread_arg) {
    long tid = (long)thread_arg;
    if (tid == 0) {
        // translate C to Cat language
        printf("Enter C code to be translated into Cat language: ");
        fgets(buffer, BUFFER_SIZE, stdin);
        for (int i = 0; buffer[i] != '\0'; i++) {
            if (buffer[i] == ';') {
                printf("Meow ");
            } else if (buffer[i] == '{') {
                printf("Purr ");
            } else if (buffer[i] == '}') {
                printf("Hiss ");
            } else if (buffer[i] == '<') {
                printf("Lick ");
            } else if (buffer[i] == '>') {
                printf("Scratch ");
            } else if (buffer[i] == '+') {
                printf("Purr Purr ");
            } else if (buffer[i] == '-') {
                printf("Hiss Hiss ");
            } else if (buffer[i] == '=') {
                printf("Meow Meow ");
            } else {
                putchar(buffer[i]);
            }
        }
    } else if (tid == 1) {
        // translate Cat to C language
        printf("Enter Cat language to be translated into C code: ");
        fgets(buffer, BUFFER_SIZE, stdin);
        for (int i = 0; buffer[i] != '\0'; i++) {
            if (buffer[i] == 'M' && buffer[i+1] == 'e' && buffer[i+2] == 'o' && buffer[i+3] == 'w') {
                printf(";");
                i += 3;
            } else if (buffer[i] == 'P' && buffer[i+1] == 'u' && buffer[i+2] == 'r' && buffer[i+3] == 'r') {
                printf("{");
                i += 3;
            } else if (buffer[i] == 'H' && buffer[i+1] == 'i' && buffer[i+2] == 's' && buffer[i+3] == 's') {
                printf("}");
                i += 3;
            } else if (buffer[i] == 'L' && buffer[i+1] == 'i' && buffer[i+2] == 'c' && buffer[i+3] == 'k') {
                printf("<");
                i += 3;
            } else if (buffer[i] == 'S' && buffer[i+1] == 'c' && buffer[i+2] == 'r' && buffer[i+3] == 'a' && buffer[i+4] == 't' && buffer[i+5] == 'c' && buffer[i+6] == 'h') {
                printf(">");
                i += 6;
            } else if (buffer[i] == 'P' && buffer[i+1] == 'u' && buffer[i+2] == 'r' && buffer[i+3] == 'r' && buffer[i+4] == 'P' && buffer[i+5] == 'u' && buffer[i+6] == 'r' && buffer[i+7] == 'r') {
                printf("+");
                i += 7;
            } else if (buffer[i] == 'H' && buffer[i+1] == 'i' && buffer[i+2] == 's' && buffer[i+3] == 's' && buffer[i+4] == 'H' && buffer[i+5] == 'i' && buffer[i+6] == 's' && buffer[i+7] == 's') {
                printf("-");
                i += 7;
            } else if (buffer[i] == 'M' && buffer[i+1] == 'e' && buffer[i+2] == 'o' && buffer[i+3] == 'w' && buffer[i+4] == 'M' && buffer[i+5] == 'e' && buffer[i+6] == 'o' && buffer[i+7] == 'w') {
                printf("=");
                i += 7;
            }
        }
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int rc;
    long t;
    for (t = 0; t < NUM_THREADS; t++) {
        rc = pthread_create(&threads[t], NULL, translate, (void*)t);
        if (rc) {
            printf("ERROR - return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }
    for (t = 0; t < NUM_THREADS; t++) {
        pthread_join(threads[t], NULL);
    }
    return 0;
}