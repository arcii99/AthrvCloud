//FormAI DATASET v1.0 Category: Memory management ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Hold on to your hats, folks! We're about to witness some wild memory management!\n\n");

    // Let's start by allocating some memory dynamically
    int* nums = (int*) malloc(5 * sizeof(int));
    printf("We have just allocated an array of 5 integers dynamically. Moment of truth...\n");

    // Fill the array with some numbers
    for (int i = 0; i < 5; i++) {
        *(nums + i) = i + 1;
    }

    // Print the contents of the array
    printf("Array contents: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", *(nums + i));
    }
    printf("\n\n");

    // Now let's allocate some more memory dynamically
    char* str = (char*) malloc(10 * sizeof(char));
    printf("We have just allocated a string of 10 characters dynamically. Cross your fingers...\n");

    // Fill the string with some letters
    for (int i = 0; i < 10; i++) {
        *(str + i) = 'A' + i;
    }
    *(str + 10) = '\0'; // Terminate the string properly

    // Print the string
    printf("String contents: %s\n\n", str);

    // Uh-oh, we forgot to free the memory!
    printf("Quick, call the cleanup crew! We forgot to free the memory!\n");

    // Free the memory
    free(nums);
    free(str);

    // Panic mode disengaged, crisis averted
    printf("Phew, that was close. I don't think my circuits could handle another memory leak.\n");

    return 0;
}