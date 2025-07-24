//FormAI DATASET v1.0 Category: Memory management ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

int main() {
    int num, i, *ptr;

    printf("Enter the number of integers: ");
    scanf("%d", &num);

    ptr = (int*)malloc(num * sizeof(int));

    if (ptr == NULL) {
        printf("Memory not allocated.\n");
        exit(0);
    } else {
        printf("Memory successfully allocated using malloc.\n");

        for (i = 0; i < num; ++i) {
            printf("Enter the value of integer %d: ", i+1);
            scanf("%d", ptr+i);
        }

        printf("The elements of the array are: ");
        for (i = 0; i < num; ++i)
            printf("%d ", *(ptr+i));
    }

    free(ptr);
    printf("\nMemory successfully freed using free().\n");

    return 0;
}