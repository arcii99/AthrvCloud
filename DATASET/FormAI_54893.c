//FormAI DATASET v1.0 Category: Error handling ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

int main() {
    int num;
    int result;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (num < 0) {
        printf("Oops, you entered a negative number! Let me try again.\n");
        printf("Enter a positive number: ");
        scanf("%d", &num);
    }

    if (num == 0) {
        printf("Zero is not allowed! Come on, give me something more exciting.\n");
        printf("Enter a non-zero number: ");
        scanf("%d", &num);
    }

    result = 100 / num;

    printf("100 divided by %d is %d. Woohoo!\n", num, result);

    printf("Thanks for playing!\n");

    return 0;
}