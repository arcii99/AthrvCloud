//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: curious
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr, i, size;

    printf("Please enter the size of the memory block: ");
    scanf("%d", &size);

    ptr = (int*) malloc(size * sizeof(int));

    if(ptr == NULL) {
        printf("Error! Memory not allocated.");
        exit(0);
    }

    printf("Memory block allocated successfully.\n");

    while(1) {
        printf("Enter 1 to monitor RAM usage or 0 to exit: ");
        scanf("%d", &i);

        if(i == 0) break;
        else if(i == 1) {
            printf("Currently using %d KB of RAM.\n", size * sizeof(int)/1024);
        }
        else {
            printf("Invalid input. Please try again.\n");
        }
    }

    free(ptr);

    return 0;
}