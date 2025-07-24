//FormAI DATASET v1.0 Category: Error handling ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void sig_handler(int sig) {
    if (sig == SIGINT) {
        printf("\nError: Received SIGINT signal. Program terminated.\n");
        exit(1);
    }
    else if (sig == SIGSEGV) {
        printf("\nError: Segmentation fault occurred. Program terminated.\n");
        exit(1);
    }
}

int main() {

    signal(SIGINT, sig_handler);
    signal(SIGSEGV, sig_handler);

    int *ptr = NULL;
    *ptr = 1; // This will cause a segmentation fault

    return 0;
}