//FormAI DATASET v1.0 Category: Data mining ; Style: Linus Torvalds
#include <stdio.h>

#define MAX_DATA 10000 

int main(void) {
    int data[MAX_DATA], range, i;

    printf("Enter the total number of data points: ");
    scanf("%d", &range);

    printf("Enter the data points: \n");
    for (i = 0; i < range; i++) {
        scanf("%d", &data[i]);
    }

    printf("Mining for data...\n");
    int max = data[0], min = data[0], sum = data[0];
    for (i = 1; i < range; i++) {
        if (data[i] > max) {
            max = data[i];
        }
        if (data[i] < min) {
            min = data[i];
        }
        sum += data[i];
    }

    printf("The maximum data point is %d\n", max);
    printf("The minimum data point is %d\n", min);
    printf("The average data point is %d\n", (sum / range));

    return 0;
}