//FormAI DATASET v1.0 Category: Memory management ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

void *cryptic_malloc(size_t size) {
    void *ptr = malloc(size);
    if(ptr == NULL) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }
    printf("Value encrypted\n");
    return ptr;
}

void cryptic_free(void *ptr) {
    printf("Value decrypted\n");
    free(ptr);
}

int main() {
    int *num = cryptic_malloc(sizeof(int));
    *num = 12345;
    printf("Secret value: %d\n", *num);
    cryptic_free(num);
    return 0;
}