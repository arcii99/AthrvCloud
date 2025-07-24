//FormAI DATASET v1.0 Category: Error handling ; Style: protected
#include<stdio.h>
#include<stdlib.h>
#include<signal.h>

/* custom signal handler function */
void handle_error(int signum, siginfo_t *info, void *ptr) {
    printf("Segmentation fault occurred\n");
    printf("Error code: %d\n", info->si_code);
    exit(EXIT_FAILURE);
}

/* function to divide two numbers */
int divide(int a, int b) {
    int *p = NULL;
    int c = a/b;   /* division by zero error */
    *p = c;       /* null pointer error */
    return c;
}

int main() {
    int a, b, result;

    /* register custom signal handler */
    struct sigaction sa;
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = handle_error;
    sigaction(SIGSEGV, &sa, NULL);

    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    result = divide(a, b);

    printf("The result of division is %d\n", result);

    return 0;
}