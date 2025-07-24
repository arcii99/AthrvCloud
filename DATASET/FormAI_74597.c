//FormAI DATASET v1.0 Category: Error handling ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

void func(int *p) {
    if (p == NULL) {
        fprintf(stderr, "Error: null pointer passed to function\n");
        exit(EXIT_FAILURE);
    }
    /* function logic here */
}

int main(void)
{
    int *p = NULL;
    int ret;

    p = malloc(sizeof(int));
    if (p == NULL) {
        perror("malloc error");
        exit(EXIT_FAILURE);
    }

    printf("Enter a positive integer: ");
    ret = scanf("%d", p);
    if (ret == 0 || *p <= 0) {
        fprintf(stderr, "Error: invalid input\n");
        free(p);
        exit(EXIT_FAILURE);
    }

    func(p);

    free(p);
    return 0;
}