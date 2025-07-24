//FormAI DATASET v1.0 Category: Memory management ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Oh my goodness, I can't believe I have to manage memory in C!\n");
    printf("I hope this program works, I don't want any Segmentation Faults!\n\n");

    int *arr = calloc(5, sizeof(int));
    if(arr == NULL) {
        printf("Oh no, I couldn't allocate memory for my array!\n");
        return 1;
    }

    printf("Phew, I managed to allocate memory for my array!\n\n");
    printf("Let me print the values of my array...\n");
    for(int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n\nNow I am going to set some values in my array...\n\n");
    for(int i = 0; i < 5; i++) {
        arr[i] = i + 1;
    }

    printf("Great, I managed to set some values in my array!\n\n");
    printf("Let me print the values of my array again...\n");
    for(int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n\nNow I am going to free the memory I allocated for my array...\n\n");
    free(arr);

    printf("Oh my goodness, I hope I don't accidentally access the memory I just freed!\n\n");
    printf("Let me try to print the values in my array again...\n");
    for(int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n\nOh no, I got a Segmentation Fault!\n");
    printf("I guess that's what happens when you don't manage your memory properly in C...\n");

    return 0;
}