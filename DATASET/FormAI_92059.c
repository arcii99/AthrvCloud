//FormAI DATASET v1.0 Category: Memory management ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

int main() {

    // You won't believe what I just did!!
    printf("Hey there! I just allocated memory using malloc() function!\n\n");
    int *p = (int*) malloc(5 * sizeof(int));
    if (p == NULL) {
        printf("Oh no! I forgot to check if malloc() returned NULL or not!\n");
        printf("I guess I'll have to exit now...\n");
        exit(1);
    }

    // Wait, there's more!
    printf("And now, I am using memcpy() function to copy some integers to the newly allocated memory!\n\n");
    int src[] = {1, 2, 3, 4, 5};
    memcpy(p, src, sizeof(src));

    // This is getting interesting!
    printf("But wait, there's more! I am going to use realloc() function now to allocate some more memory!\n\n");
    int *q = (int*) realloc(p, 10 * sizeof(int));
    if (q == NULL) {
        printf("Uh oh, realloc() failed! I better exit now...\n");
        free(p);
        exit(1);
    }
    p = q;

    // Surprise, surprise!
    printf("And now, I am using memmove() function to move some of the integers in the array!\n\n");
    memmove(p + 2, p, 3 * sizeof(int));
    printf("The array now contains: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", p[i]);
    }
    printf("\n");

    // This is getting out of hand...
    printf("Now, I am using calloc() function to allocate and initialize some memory!\n\n");
    int *r = (int*) calloc(3, sizeof(int));
    if (r == NULL) {
        printf("Oh boy, another memory allocation failure! I'm done with this program!\n");
        free(p);
        exit(1);
    }

    // Let's finish this!
    printf("Now, I am using free() function to free up all the allocated memory...\n\n");
    free(p);
    free(r);
    printf("Phew, that was quite a ride! :)");

    return 0;
}