//FormAI DATASET v1.0 Category: Math exercise ; Style: Ada Lovelace
#include <stdio.h>

int main() {
    int num, i, sum = 0;
    float avg;
    printf("Enter 10 numbers:\n");
    for (i = 0; i < 10; i++) {
        scanf("%d", &num);
        sum += num;
    }
    avg = (float) sum / 10.0;
    printf("Average = %.2f", avg);
    return 0;
}