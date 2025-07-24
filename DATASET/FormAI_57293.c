//FormAI DATASET v1.0 Category: Random ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

int recursive_rand(int lower, int upper) {
    if(lower == upper) {
        return lower;
    } else {
        return rand() % (upper - lower + 1) + lower;
    }
}

int main() {
    int lower, upper, num;

    printf("Enter the lower limit: ");
    scanf("%d", &lower);
    printf("Enter the upper limit: ");
    scanf("%d", &upper);
    printf("How many random numbers do you want? ");
    scanf("%d", &num);

    for(int i=0; i<num; i++) {
        printf("%d\n", recursive_rand(lower,upper));
    }

    return 0;
}