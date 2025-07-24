//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int num1 = rand() % 100 + 1;
    int num2 = rand() % 50 + 1;
    int sum = num1 + num2;
    printf("The first random number is %d\n", num1);
    printf("The second random number is %d\n", num2);
    printf("The sum of the two random numbers is %d\n", sum);
    int count = 0;
    for (int i = 0; i < sum; i++) {
        if (i % num1 == 0 || i % num2 == 0) {
            printf("%d ", i);
            count++;
            if (count == 10) {
                printf("\n");
                count = 0;
            }
        }
    }
    printf("\n");
    return 0;
}