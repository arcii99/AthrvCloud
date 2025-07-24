//FormAI DATASET v1.0 Category: Funny ; Style: sophisticated
#include <stdio.h>

int main()
{
    int eggs = 0;
    printf("How many eggs are in the basket? ");
    scanf("%d", &eggs);

    if (eggs <= 0) {
        printf("There are no eggs to count.\n");
    } else if (eggs == 1) {
        printf("There is only one egg in the basket.\n");
    } else if (eggs == 2) {
        printf("There are a pair of eggs in the basket.\n");
    } else if (eggs % 2 == 0) {
        printf("There are %d eggs in the basket. That's an even number!\n", eggs);
    } else if (eggs == 3) {
        printf("There are three eggs in a row.\n");
    } else if (eggs < 12) {
        printf("There are %d eggs in the basket, but no dozen yet.\n", eggs);
    } else if (eggs == 12) {
        printf("There is a dozen eggs in the basket.\n");
    } else if (eggs < 144) {
        printf("There are %d eggs in the basket. That's %d dozen!\n", eggs, eggs/12);
    } else {
        printf("That's a lot of eggs!\n");
    }

    return 0;
}