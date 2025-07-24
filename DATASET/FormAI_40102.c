//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: mind-bending
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_NUM 10000

int main() {
    bool isPrime[MAX_NUM];
    int i, j, num, count = 0;

    for (i = 2; i <= MAX_NUM; i++)
        isPrime[i] = true;

    for (i = 2; i <= MAX_NUM; i++) {
        if (isPrime[i]) {
            printf("%d ", i);
            count++;
            for (j = i * 2; j <= MAX_NUM; j += i)
                isPrime[j] = false;
        }
        if (count % 10 == 0)
            printf("\n");
    }

    return 0;
}