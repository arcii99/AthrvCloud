//FormAI DATASET v1.0 Category: Memory management ; Style: introspective
#include<stdio.h>
#include<stdlib.h>

void print_mem() {
    FILE *fp;
    char buffer[1024];
    fp = fopen("/proc/self/maps", "r");
    while (fgets(buffer, sizeof(buffer), fp)) {
        printf("%s", buffer);
    }
    fclose(fp);
}

int main() {
    printf("Initial Memory Map:\n");
    print_mem();

    int *ptr1 = (int *) malloc(sizeof(int));
    printf("Allocated Memory Map After ptr1:\n");
    print_mem();

    int *ptr2 = (int *) malloc(3 * sizeof(int));
    printf("Allocated Memory Map After ptr2:\n");
    print_mem();

    int *ptr3 = (int *) calloc(1, sizeof(int));
    printf("Allocated Memory Map After ptr3:\n");
    print_mem();

    int *ptr4 = (int *) realloc(ptr2, 5 * sizeof(int));
    printf("Allocated Memory Map After ptr4:\n");
    print_mem();

    free(ptr1);
    free(ptr3);
    free(ptr4);
    printf("Allocated Memory Map After freeing ptr1, ptr3 and ptr4:\n");
    print_mem();

    return 0;
}