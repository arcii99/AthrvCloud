//FormAI DATASET v1.0 Category: Pattern printing ; Style: surprised
#include <stdio.h>

int main() {
    int height;
    printf("Oh my goodness, what beautiful pattern would you like me to print? Please enter the height (odd number only): ");
    scanf("%d", &height);

    while(height % 2 == 0) {
        printf("Oh no, you entered an even number! This won't work, please enter an odd number: ");
        scanf("%d", &height);
    }

    printf("Awesome, get ready to be amazed!\n\n");

    int i, j, k = height;

    for(i = 1; i <= height; i += 2, k -= 2) {
        for(j = 1; j <= k/2; j++) {
            printf(" ");
        }

        for(j = 1; j <= i; j++) {
            printf("*");
        }

        printf("\n");
    }

    k = 3;

    for(i = height-2; i >= 1; i -= 2, k += 2) {
        for(j = 1; j <= k/2; j++) {
            printf(" ");
        }

        for(j = 1; j <= i; j++) {
            printf("*");
        }

        printf("\n");
    }

    printf("\nWow, I can't believe I just printed that! :)");

    return 0;
}