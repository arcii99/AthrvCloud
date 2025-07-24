//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define LENGTH 1000000

int main() {
    int *arr = malloc(sizeof(int) * LENGTH);
    bool *flags = calloc(LENGTH, sizeof(bool));

    for (int i = 0; i < LENGTH; i++) {
        arr[i] = i + 1;
    }

    for (int i = 0; i < LENGTH; i++) {
        if (!flags[i]) {
            int num = arr[i];
            printf("%d\n", num);

            for (int j = i; j < LENGTH; j += num) {
                flags[j] = true;
            }
        }
    }

    free(arr);
    free(flags);

    return 0;
}