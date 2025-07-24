//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100000

typedef struct {
    char str[20];
} mystruct_t;

int compare(const void *a, const void *b);

int main() {
    mystruct_t arr[MAX_SIZE];
    int i, j, n;
    char buffer[20];

    printf("Enter number of elements (max %d): ", MAX_SIZE);
    scanf("%d", &n);

    // Input
    printf("Enter %d strings, each not exceeding 19 characters:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%s", arr[i].str);
    }

    // Sort
    qsort(arr, n, sizeof(mystruct_t), compare);

    // Output
    printf("\nThe Strings in alphabetical order are:\n");
    for (i = 0; i < n; i++) {
        printf("%s\n", arr[i].str);
    }

    return 0;
}

int compare(const void *a, const void *b) {
    mystruct_t *ia = (mystruct_t *) a;
    mystruct_t *ib = (mystruct_t *) b;
    return strcmp(ia->str, ib->str);
}