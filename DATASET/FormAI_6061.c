//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: puzzling
#include<stdio.h>

int main(int argc, char *argv[]) {
    int i, j, flag, n, count = 0;

    printf("How many prime numbers do you want to generate? ");
    scanf("%d", &n);

    printf("Generating...\nPrime numbers are: ");
    for (i = 2; count < n; i++) {
        flag = 0;
        for (j = 2; j <= i / 2; j++) {
            if (i % j == 0) {
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            printf("%d ", i);
            count++;
        }
    }
    printf("\n");

    return 0;
}