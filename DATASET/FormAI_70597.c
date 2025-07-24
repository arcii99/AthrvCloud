//FormAI DATASET v1.0 Category: Error handling ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

int main() {

    int num = 0;
    printf("Enter a number between 1 and 10:");

    scanf("%d", num);

    if (num < 1 || num > 10) {
        printf("Are you trying to break me?!? Enter a number between 1 and 10!");
        exit(1);
    }

    int result = 10/num;

    if (result == 0) {
        int *test = NULL;
        *test = 10;
    }

    return 0;
}